
/* 1. Import Express and createPool */
import express from "express";
import { createPool } from "mysql2/promise";

/* 2. Create the Express application */
const app = express();

/* 3. Register middleware to read JSON request bodies */
app.use(express.json());

/* 4. Create the MySQL connection pool */
const sqlConnectionPool = createPool({
  host: "localhost",
  port: 3306,
  user: "root",
  password: "Sanket@2005",
  database: "productdb",
  connectionLimit: 10
});

/* 5. Define the API routes */

// GET: Get all products
app.get("/product", async (req, res) => {
  try {
    const query = "SELECT * FROM product";
    const [rows] = await sqlConnectionPool.query(query);

    res.status(200).json(rows);
  } catch (error) {
    console.error("GET products error:", error.message);
    res.status(500).json({ message: "Failed to fetch products" });
  }
});

// GET: Get one product by ID
app.get("/product/:id", async (req, res) => {
  try {
    const id = Number(req.params.id);

    if (!Number.isInteger(id) || id < 1) {
      return res.status(400).json({ message: "Invalid product ID" });
    }

    const query = "SELECT * FROM product WHERE id = ?";
    const [rows] = await sqlConnectionPool.query(query, [id]);

    if (rows.length === 0) {
      return res.status(404).json({ message: "Product not found" });
    }

    res.status(200).json(rows[0]);
  } catch (error) {
    console.error("GET product error:", error.message);
    res.status(500).json({ message: "Failed to fetch product" });
  }
});

// POST: Create a new product
app.post("/product", async (req, res) => {
  try {
    const { name, price, description, qty } = req.body;

    if (
      typeof name !== "string" ||
      !name.trim() ||
      typeof price !== "number" ||
      !Number.isFinite(price) ||
      price < 0 ||
      typeof description !== "string" ||
      !Number.isInteger(qty) ||
      qty < 0
    ) {
      return res.status(400).json({
        message: "Provide a name, non-negative price, description, and non-negative integer quantity"
      });
    }

    const query = `
      INSERT INTO product (name, price, description, qty)
      VALUES (?, ?, ?, ?)
    `;

    const [result] = await sqlConnectionPool.query(query, [
      name.trim(),
      price,
      description,
      qty
    ]);

    res.status(201).json({
      message: "Product created successfully",
      id: result.insertId
    });
  } catch (error) {
    console.error("POST product error:", error.message);
    res.status(500).json({ message: "Failed to create product" });
  }
});

// PUT: Update an existing product
app.put("/product/:id", async (req, res) => {
  try {
    const id = Number(req.params.id);
    const { name, price, description, qty } = req.body;

    if (!Number.isInteger(id) || id < 1) {
      return res.status(400).json({ message: "Invalid product ID" });
    }

    if (
      typeof name !== "string" ||
      !name.trim() ||
      typeof price !== "number" ||
      !Number.isFinite(price) ||
      price < 0 ||
      typeof description !== "string" ||
      !Number.isInteger(qty) ||
      qty < 0
    ) {
      return res.status(400).json({
        message: "Invalid product data"
      });
    }

    const query = `
      UPDATE product
      SET name = ?, price = ?, description = ?, qty = ?
      WHERE id = ?
    `;

    const [result] = await sqlConnectionPool.query(query, [
      name.trim(),
      price,
      description,
      qty,
      id
    ]);

    if (result.affectedRows === 0) {
      const [rows] = await sqlConnectionPool.query(
        "SELECT id FROM product WHERE id = ?",
        [id]
      );

      if (rows.length === 0) {
        return res.status(404).json({ message: "Product not found" });
      }
    }

    res.status(200).json({ message: "Product updated successfully" });
  } catch (error) {
    console.error("PUT product error:", error.message);
    res.status(500).json({ message: "Failed to update product" });
  }
});

// DELETE: Delete a product
app.delete("/product/:id", async (req, res) => {
  try {
    const id = Number(req.params.id);

    if (!Number.isInteger(id) || id < 1) {
      return res.status(400).json({ message: "Invalid product ID" });
    }

    const query = "DELETE FROM product WHERE id = ?";
    const [result] = await sqlConnectionPool.query(query, [id]);

    if (result.affectedRows === 0) {
      return res.status(404).json({ message: "Product not found" });
    }

    res.status(200).json({ message: "Product deleted successfully" });
  } catch (error) {
    console.error("DELETE product error:", error.message);
    res.status(500).json({ message: "Failed to delete product" });
  }
});

/* 6. Start the server */
app.listen(7500, () => {
  console.log("Server running at http://localhost:7500");
});

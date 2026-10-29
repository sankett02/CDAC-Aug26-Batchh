import db from "../db.js";

// GET all products
export const getProducts = async (req, res) => {
    try {
        const [rows] = await db.query(
            "SELECT * FROM product"
        );

        res.status(200).json(rows);
    } catch (error) {
        console.error(error);

        res.status(500).json({
            message: "Failed to fetch products"
        });
    }
};

// GET one product
export const getProductById = async (req, res) => {
    try {
        const id = Number(req.params.id);

        if (!Number.isInteger(id) || id < 1) {
            return res.status(400).json({
                message: "Invalid product ID"
            });
        }

        const [rows] = await db.execute(
            "SELECT * FROM product WHERE id = ?",
            [id]
        );

        if (rows.length === 0) {
            return res.status(404).json({
                message: "Product not found"
            });
        }

        res.status(200).json(rows[0]);
    } catch (error) {
        console.error(error);

        res.status(500).json({
            message: "Failed to fetch product"
        });
    }
};

// CREATE product
export const createProduct = async (req, res) => {
    try {
        const { name, price, quantity } = req.body;

        const [result] = await db.execute(
            `INSERT INTO product (name, price, quantity)
             VALUES (?, ?, ?)`,
            [name, price, quantity]
        );

        res.status(201).json({
            message: "Product created successfully",
            id: result.insertId
        });
    } catch (error) {
        console.error(error);

        res.status(500).json({
            message: "Failed to create product"
        });
    }
};

// UPDATE product
export const updateProduct = async (req, res) => {
    try {
        const id = Number(req.params.id);

        if (!Number.isInteger(id) || id < 1) {
            return res.status(400).json({
                message: "Invalid product ID"
            });
        }

        const { name, price, quantity } = req.body;

        const [result] = await db.execute(
            `UPDATE product
             SET name = ?, price = ?, quantity = ?
             WHERE id = ?`,
            [name, price, quantity, id]
        );

        if (result.affectedRows === 0) {
            return res.status(404).json({
                message: "Product not found"
            });
        }

        res.status(200).json({
            message: "Product updated successfully"
        });
    } catch (error) {
        console.error(error);

        res.status(500).json({
            message: "Failed to update product"
        });
    }
};

// DELETE product
export const deleteProduct = async (req, res) => {
    try {
        const id = Number(req.params.id);

        if (!Number.isInteger(id) || id < 1) {
            return res.status(400).json({
                message: "Invalid product ID"
            });
        }

        const [result] = await db.execute(
            "DELETE FROM product WHERE id = ?",
            [id]
        );

        if (result.affectedRows === 0) {
            return res.status(404).json({
                message: "Product not found"
            });
        }

        res.status(200).json({
            message: "Product deleted successfully"
        });
    } catch (error) {
        console.error(error);

        res.status(500).json({
            message: "Failed to delete product"
        });
    }
};
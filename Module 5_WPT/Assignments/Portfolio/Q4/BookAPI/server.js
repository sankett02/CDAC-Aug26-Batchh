
const express = require("express");
const cors = require("cors");

const app = express();
const PORT = 5000;

// Middleware
app.use(cors());
app.use(express.json());

// In-memory array
const books = [];
let nextId = 1;

// POST API to add a book
app.post("/books", (req, res) => {
  const { name, author, price } = req.body;

  // Validate input
  if (
    typeof name !== "string" || !name.trim() ||
    typeof author !== "string" || !author.trim() ||
    price === undefined || price === null ||
    String(price).trim() === "" ||
    !Number.isFinite(Number(price)) ||
    Number(price) < 0
  ) {
    return res.status(400).json({
      error: "Enter a valid book name, author, and non-negative price."
    });
  }

  // Create book object
  const book = {
    Id: nextId++,
    Name: name.trim(),
    Author: author.trim(),
    Price: Number(price)
  };

  // Store book in array
  books.push(book);

  // Return newly added book
  res.status(201).json(book);
});

// Start server
app.listen(PORT, () => {
  console.log(`Server running at http://localhost:3000`);
});

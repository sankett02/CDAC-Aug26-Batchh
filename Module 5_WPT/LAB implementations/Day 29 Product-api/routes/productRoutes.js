import express from "express";

import {
    getProducts,
    getProductById,
    createProduct,
    updateProduct,
    deleteProduct
} from "../Controller/productController.js";

import validateProduct from "../middleware/validateProduct.js";

const router = express.Router();

// GET all products
router.get("/", getProducts);

// GET one product
router.get("/:id", getProductById);

// CREATE product
router.post("/", validateProduct, createProduct);

// UPDATE product
router.put("/:id", validateProduct, updateProduct);

// DELETE product
router.delete("/:id", deleteProduct);

export default router;
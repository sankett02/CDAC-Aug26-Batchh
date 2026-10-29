import express from "express";
import logger from "./middleware/logger.js";
import productRoutes from "./routes/productRoutes.js";

const app = express();

// Middleware
app.use(express.json());
app.use(logger);

// Routes
app.use("/product", productRoutes);

// Start server
app.listen(7500, () => {
    console.log("Server running at http://localhost:7500");
});
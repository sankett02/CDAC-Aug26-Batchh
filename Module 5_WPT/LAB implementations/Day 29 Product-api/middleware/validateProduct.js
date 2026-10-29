function validateProduct(req, res, next) {
    const { name, price, quantity } = req.body;

    if (
        typeof name !== "string" ||
        name.trim() === ""
    ) {
        return res.status(400).json({
            message: "Product name is required"
        });
    }

    if (
        price === undefined ||
        price === null ||
        price === "" ||
        !Number.isFinite(Number(price)) ||
        Number(price) < 0
    ) {
        return res.status(400).json({
            message: "Price must be a valid non-negative number"
        });
    }

    if (
        quantity === undefined ||
        quantity === null ||
        quantity === "" ||
        !Number.isInteger(Number(quantity)) ||
        Number(quantity) < 0
    ) {
        return res.status(400).json({
            message: "Quantity must be a non-negative integer"
        });
    }

    req.body.name = name.trim();
    req.body.price = Number(price);
    req.body.quantity = Number(quantity);

    next();
}

export default validateProduct;

console.log("===== DAY 24 PRACTICE =====");

// 1. FUNCTION DECLARATION
function rectangleArea(width, height) {
  return width * height;
}

console.log("Rectangle area:", rectangleArea(5, 3));

// 2. ARROW FUNCTION
const square = (number) => {
  return number * number;
};

console.log("Square of 6:", square(6));

// Short arrow function
const double = number => number * 2;
console.log("Double of 10:", double(10));

// 3. ARRAY METHODS
const prices = [100, 250, 75, 400];

// filter(): select values that match a condition
const expensivePrices = prices.filter(price => price > 100);
console.log("Prices above 100:", expensivePrices);

// map(): transform each value
const pricesWithTax = prices.map(price => price * 1.10);
console.log("Prices with 10% tax:", pricesWithTax);

// reduce(): combine values into one result
const total = prices.reduce((sum, price) => sum + price, 0);
console.log("Total price:", total);

// 4. OBJECTS
const person = {
  name: "Ravi",
  age: 22,
  city: "Pune"
};

console.log("Name:", person.name);
console.log("City:", person["city"]);

// 5. DYNAMIC PROPERTY ACCESS
const propertyName = "city";

console.log("Dynamic property:", person[propertyName]);

// 6. OBJECT DESTRUCTURING
const { name, age, city } = person;

console.log(`${name} is ${age} years old and lives in ${city}.`);

// 7. ARRAY OF OBJECTS — COMMON IN BACKEND APIs
const products = [
  { id: 1, name: "Notebook", price: 50 },
  { id: 2, name: "Pen", price: 10 },
  { id: 3, name: "Bag", price: 800 }
];

// Find products costing more than 100
const costlyProducts = products.filter(product => product.price > 100);
console.log("Costly products:", costlyProducts);

// Return only product names
const productNames = products.map(product => product.name);
console.log("Product names:", productNames);

// Calculate total value of all products
const inventoryValue = products.reduce(
  (total, product) => total + product.price,
  0
);

console.log("Inventory value:", inventoryValue);

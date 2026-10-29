
const fs = require("fs");

// Step 1: Read numbers from the file
const data = fs.readFileSync("numbers.txt", "utf8");

// Step 2: Convert file contents into an array of numbers
const numbers = data.trim().split(/\s+/).map(Number);

// Step 3: Calculate square of each number
const squares = numbers.map(function(num) {
    return num * num;
});

// Step 4: Display squares
console.log("Squares of numbers:");

squares.forEach(function(square) {
    console.log(square);
});

// Step 5: Calculate sum of squares
const sum = squares.reduce(function(total, square) {
    return total + square;
}, 0);

// Step 6: Calculate average of original numbers
const originalSum = numbers.reduce(function(total, num) {
    return total + num;
}, 0);

const average = originalSum / numbers.length;

// Step 7: Display results
console.log("Total:", sum);
console.log("Average:", average);

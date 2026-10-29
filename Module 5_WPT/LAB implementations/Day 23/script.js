
console.log("===== DAY 23 PRACTICE =====");

// 1. VARIABLES
const studentName = "Asha";
let age = 20;
const isLearning = true;

console.log("Name:", studentName);
console.log("Age:", age);
console.log("Is learning JavaScript?", isLearning);

// 2. OPERATORS
const a = 12;
const b = 4;

console.log("Addition:", a + b);
console.log("Subtraction:", a - b);
console.log("Multiplication:", a * b);
console.log("Division:", a / b);
console.log("Is a greater than b?", a > b);

// 3. CONDITIONS
const marks = 76;

if (marks >= 90) {
  console.log("Grade A");
} else if (marks >= 70) {
  console.log("Grade B");
} else {
  console.log("Keep practising");
}

// 4. FUNCTIONS
function add(x, y) {
  return x + y;
}

const answer = add(5, 7);
console.log("Function result:", answer);

// 5. ARRAYS AND LOOPS
const topics = ["Variables", "Conditions", "Functions"];

for (const topic of topics) {
  console.log("Practise:", topic);
}

// 6. OBJECTS
const learner = {
  name: "Asha",
  skill: "JavaScript",
  level: "Beginner"
};

console.log("Learner name:", learner.name);
console.log("Learner skill:", learner["skill"]);

// 7. BROWSER CLICK EVENT
const button = document.querySelector("#helloBtn");
const output = document.querySelector("#output");

button.addEventListener("click", function () {
  output.textContent = `Hello, ${studentName}! Keep learning JavaScript.`;
});

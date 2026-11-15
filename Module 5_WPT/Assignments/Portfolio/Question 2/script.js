
function calculate(operation) {
    const num1 = document.getElementById("num1").value;
    const num2 = document.getElementById("num2").value;

    const result = document.getElementById("result");
    const error = document.getElementById("error");

    // Validate the input fields
    if (num1 === "" || num2 === "") {
        error.textContent = "Please enter both numbers!";
        result.textContent = "";
        return;
    }

    const a = Number(num1);
    const b = Number(num2);
    let answer;

    // Perform the selected operation
    if (operation === "multiply") {
        answer = a * b;
    } else if (operation === "divide") {
        if (b === 0) {
            error.textContent = "Cannot divide by zero!";
            result.textContent = "";
            return;
        }

        answer = a / b;
    }

    error.textContent = "";
    result.textContent = answer;
}

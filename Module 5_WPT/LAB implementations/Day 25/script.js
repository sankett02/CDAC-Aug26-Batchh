
const form = document.querySelector("#signupForm");
const message = document.querySelector("#message");

form.addEventListener("submit", function (event) {
  // Stop the browser from reloading the page
  event.preventDefault();

  // Read the user's input
  const name = document.querySelector("#name").value.trim();
  const email = document.querySelector("#email").value.trim();
  const password = document.querySelector("#password").value;

  // A simple email pattern for practice
  const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

  // Validate the name
  if (name.length < 2) {
    showMessage("Name must have at least 2 characters.", false);
    return;
  }

  // Validate the email
  if (!emailPattern.test(email)) {
    showMessage("Please enter a valid-looking email.", false);
    return;
  }

  // Validate the password
  if (password.length < 8) {
    showMessage("Password must have at least 8 characters.", false);
    return;
  }

  // All practice checks passed
  showMessage(`Welcome, ${name}! The form looks valid.`, true);
});

function showMessage(text, isSuccess) {
  message.textContent = text;
  message.className = isSuccess ? "success" : "error";
}

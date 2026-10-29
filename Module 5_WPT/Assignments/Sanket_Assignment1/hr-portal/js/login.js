/**
 * ==============================================================================
 * TECHNOVA HR PORTAL - LOGIN SCRIPT (login.js)
 * Author: Sanket Ambre
 * Description: Password visibility toggle via setAttribute, real-time password
 *              regex validation (onkeyup), and form submission handler.
 * ==============================================================================
 */

/**
 * 1. Toggle Password Visibility using setAttribute
 * Switches input type between "password" and "text" and toggles button text
 */
function togglePasswordVisibility() {
  const pwdInput = document.getElementById("password-input");
  const toggleBtn = document.getElementById("toggle-pwd-btn");

  if (pwdInput.getAttribute("type") === "password") {
    pwdInput.setAttribute("type", "text");
    toggleBtn.innerHTML = "Hide";
  } else {
    pwdInput.setAttribute("type", "password");
    toggleBtn.innerHTML = "Show";
  }
}

/**
 * 2. Validate Username
 * Username is required and must not be blank.
 */
function checkUsername() {
  const usernameInput = document.getElementById("username-input");
  const errorSpan = document.getElementById("username-error");
  const val = usernameInput.value.trim();

  if (val === "") {
    errorSpan.innerHTML = "Username is required.";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * 3. Validate Password with Regular Expression (onkeyup)
 * Rule: At least 8 characters with at least one uppercase letter,
 *       one lowercase letter, one number, and one special character.
 */
function checkPassword() {
  const pwdInput = document.getElementById("password-input");
  const errorSpan = document.getElementById("password-error");
  const val = pwdInput.value;

  // Regex enforcing: >= 8 chars, 1 uppercase, 1 lowercase, 1 number, 1 special character
  const pwdRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&#^_\-])[A-Za-z\d@$!%*?&#^_\-]{8,}$/;

  if (val === "") {
    errorSpan.innerHTML = "Password is required.";
    return false;
  } else if (!pwdRegex.test(val)) {
    errorSpan.innerHTML = "Password must have &ge;8 chars with 1 uppercase, 1 lowercase, 1 number, and 1 special symbol (@$!%*?&#^_-).";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * 4. Main Validation on Submit
 * Invoked by onsubmit="return validate()".
 * Checks both username and password. If either fails, cancels submission.
 */
function validate() {
  const isUserValid = checkUsername();
  const isPwdValid = checkPassword();

  if (!isUserValid || !isPwdValid) {
    console.warn("Login attempt blocked: credential validation rules failed.");
    return false;
  }

  // Credentials pass validation!
  const username = document.getElementById("username-input").value.trim();
  alert(`Authentication successful! Welcome, ${username}. Redirecting to Employee Directory...`);
  window.location.href = "directory.html";
  return false; // Prevent traditional POST reload for seamless SPA simulation
}

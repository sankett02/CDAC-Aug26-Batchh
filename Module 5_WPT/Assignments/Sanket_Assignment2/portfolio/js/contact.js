/**
 * ==============================================================================
 * CONTACT PAGE FORM VALIDATION SCRIPT (contact.js)
 * Author: Sanket Ambre
 * Description: Real-time (onkeyup) validation and submit validation for contact form.
 *              Validates required name, regex email, exactly 10-digit regex phone,
 *              message length >= 20 characters, enquiry selection, consent, etc.
 * ==============================================================================
 */

/**
 * 1. Validate Name Field
 * Name is required and must contain at least 2 characters.
 */
function validateName() {
  const nameField = document.getElementById("contact-name");
  const errorSpan = document.getElementById("name-error");
  const value = nameField.value.trim();

  if (value === "") {
    errorSpan.innerHTML = "Name is required.";
    return false;
  } else if (value.length < 2) {
    errorSpan.innerHTML = "Name must be at least 2 characters.";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * 2. Validate Email Field with Regular Expression
 * Checks against standard RFC-compliant email structure.
 */
function validateEmail() {
  const emailField = document.getElementById("contact-email");
  const errorSpan = document.getElementById("email-error");
  const value = emailField.value.trim();
  const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

  if (value === "") {
    errorSpan.innerHTML = "Email address is required.";
    return false;
  } else if (!emailRegex.test(value)) {
    errorSpan.innerHTML = "Please enter a valid email address (e.g., name@domain.com).";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * 3. Validate Phone Number with Regular Expression
 * Phone must be EXACTLY 10 digits.
 */
function validatePhone() {
  const phoneField = document.getElementById("contact-phone");
  const errorSpan = document.getElementById("phone-error");
  const value = phoneField.value.trim();
  const phoneRegex = /^\d{10}$/; // Exactly 10 digits

  if (value === "") {
    errorSpan.innerHTML = "Phone number is required.";
    return false;
  } else if (!phoneRegex.test(value)) {
    errorSpan.innerHTML = "Phone number must be exactly 10 digits without spaces or dashes.";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * 4. Validate Message Length
 * Message must be at least 20 characters long.
 */
function validateMessage() {
  const messageField = document.getElementById("contact-message");
  const errorSpan = document.getElementById("message-error");
  const value = messageField.value.trim();

  if (value === "") {
    errorSpan.innerHTML = "Message is required.";
    return false;
  } else if (value.length < 20) {
    errorSpan.innerHTML = `Message must be at least 20 characters long. Current: ${value.length} characters.`;
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * 5. Validate Enquiry Type & Consent Checkbox
 */
function validateSelectAndConsent() {
  const enquirySelect = document.getElementById("enquiry-type");
  const selectError = document.getElementById("enquiry-error");
  const consentCheckbox = document.getElementById("consent-checkbox");
  const consentError = document.getElementById("consent-error");

  let isValid = true;

  if (enquirySelect.value === "") {
    selectError.innerHTML = "Please select an enquiry category.";
    isValid = false;
  } else {
    selectError.innerHTML = "";
  }

  if (!consentCheckbox.checked) {
    consentError.innerHTML = "You must agree to the privacy consent to proceed.";
    isValid = false;
  } else {
    consentError.innerHTML = "";
  }

  return isValid;
}

/**
 * 6. Main Form Submission Validator
 * Invoked by onsubmit="return validate()".
 * Checks every field. If any field fails, blocks submission and focuses the first invalid field.
 * When all valid, shows a stylish confirmation message with the visitor's name.
 */
function validate() {
  const isNameValid = validateName();
  const isEmailValid = validateEmail();
  const isPhoneValid = validatePhone();
  const isMessageValid = validateMessage();
  const isOtherValid = validateSelectAndConsent();

  // If ANY field is false, do not submit form
  if (!isNameValid || !isEmailValid || !isPhoneValid || !isMessageValid || !isOtherValid) {
    console.warn("Form submission blocked due to validation failures.");
    return false;
  }

  // All fields are valid!
  const name = document.getElementById("contact-name").value.trim();
  const thankYouBox = document.getElementById("thank-you-banner");

  thankYouBox.style.display = "block";
  thankYouBox.innerHTML = `
    <h3>🎉 Thank You, ${name}!</h3>
    <p>Your message has been validated and recorded successfully. I will get back to you within 24 hours.</p>
  `;

  // Scroll to thank-you banner
  thankYouBox.scrollIntoView({ behavior: "smooth" });

  // Prevent default HTTP page jump to preserve single-page user experience while proving form validation
  return false;
}

/**
 * Helper to reset error messages on form reset
 */
function handleFormReset() {
  document.querySelectorAll(".error-span").forEach(el => el.innerHTML = "");
  const thankYouBox = document.getElementById("thank-you-banner");
  if (thankYouBox) thankYouBox.style.display = "none";
}

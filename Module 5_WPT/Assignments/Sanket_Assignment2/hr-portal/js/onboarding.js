/**
 * ==============================================================================
 * TECHNOVA HR PORTAL - ONBOARDING SCRIPT (onboarding.js)
 * Author: Sanket Ambre
 * Description: Validates corporate onboarding form with regex, dropdown checks,
 *              and chains sequential asynchronous onboarding steps via Promises
 *              with .then() and .catch().
 * ==============================================================================
 */

/**
 * Validation Helper Functions
 */
function validateFullName() {
  const nameInput = document.getElementById("ob-fullname");
  const errorSpan = document.getElementById("ob-fullname-error");
  const val = nameInput.value.trim();

  if (val === "") {
    errorSpan.innerHTML = "Full name is required.";
    return false;
  } else if (val.length < 3) {
    errorSpan.innerHTML = "Full name must be at least 3 characters long.";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

function validateOfficialEmail() {
  const emailInput = document.getElementById("ob-email");
  const errorSpan = document.getElementById("ob-email-error");
  const val = emailInput.value.trim();
  // Regex enforcing valid email format with @technova.com corporate domain
  const emailRegex = /^[a-zA-Z0-9._%+-]+@technova\.com$/i;

  if (val === "") {
    errorSpan.innerHTML = "Official email is required.";
    return false;
  } else if (!emailRegex.test(val)) {
    errorSpan.innerHTML = "Email must end with corporate domain @technova.com (e.g. name@technova.com).";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

function validateDropdowns() {
  const qualSelect = document.getElementById("ob-qualification");
  const deptSelect = document.getElementById("ob-department");
  const qualError = document.getElementById("ob-qualification-error");
  const deptError = document.getElementById("ob-department-error");

  let valid = true;

  if (qualSelect.value === "") {
    qualError.innerHTML = "Please select highest qualification.";
    valid = false;
  } else {
    qualError.innerHTML = "";
  }

  if (deptSelect.value === "") {
    deptError.innerHTML = "Please assign a department.";
    valid = false;
  } else {
    deptError.innerHTML = "";
  }

  return valid;
}

function validateDeclaration() {
  const declCheckbox = document.getElementById("ob-declaration");
  const errorSpan = document.getElementById("ob-declaration-error");

  if (!declCheckbox.checked) {
    errorSpan.innerHTML = "You must confirm that all details are accurate.";
    return false;
  } else {
    errorSpan.innerHTML = "";
    return true;
  }
}

/**
 * ------------------------------------------------------------------------------
 * PROMISE CHAINING ONBOARDING PIPELINE
 * Each step is a function that returns a Promise.
 * ------------------------------------------------------------------------------
 */

// Step 1: Account Creation (1000ms)
function createAccountStep(candidateName) {
  return new Promise((resolve, reject) => {
    // Failure condition: if candidate name is under 3 letters, reject
    if (!candidateName || candidateName.trim().length < 3) {
      reject("Account creation rejected: Candidate name must be at least 3 characters long.");
      return;
    }

    addStepProgressItem("step-1", "⏳ Creating your account in TechNova Active Directory...", "active");

    setTimeout(() => {
      completeStepProgressItem("step-1", "✅ Step 1: Account created successfully.");
      resolve({ candidateName, accountId: "EMP-" + Math.floor(1000 + Math.random() * 9000) });
    }, 1000);
  });
}

// Step 2: Welcome Email Dispatch (2000ms)
function sendWelcomeEmailStep(data) {
  return new Promise((resolve, reject) => {
    addStepProgressItem("step-2", "⏳ Sending welcome email with corporate handbook & credentials...", "active");

    setTimeout(() => {
      completeStepProgressItem("step-2", `✅ Step 2: Welcome email dispatched to candidate (Ref: ${data.accountId}).`);
      resolve(data);
    }, 2000);
  });
}

// Step 3: Hardware Provisioning (1500ms)
function assignLaptopStep(data) {
  return new Promise((resolve, reject) => {
    addStepProgressItem("step-3", "⏳ Assigning your laptop and IT security token...", "active");

    setTimeout(() => {
      completeStepProgressItem("step-3", "✅ Step 3: High-performance workstation assigned and provisioned.");
      resolve(data);
    }, 1500);
  });
}

/**
 * UI Step Helpers
 */
function addStepProgressItem(id, text, statusClass) {
  const container = document.getElementById("onboarding-steps-container");
  const div = document.createElement("div");
  div.id = id;
  div.className = `step-item ${statusClass}`;
  div.innerHTML = text;
  container.appendChild(div);
  div.scrollIntoView({ behavior: "smooth" });
}

function completeStepProgressItem(id, text) {
  const el = document.getElementById(id);
  if (el) {
    el.className = "step-item success";
    el.innerHTML = text;
  }
}

/**
 * Main Onboarding Submission Handler
 * Validates form, prevents reload (returns false),
 * and chains promises using .then() and .catch().
 */
function handleOnboardingSubmit(event) {
  // Prevent browser default page refresh
  if (event) event.preventDefault();

  const isNameOk = validateFullName();
  const isEmailOk = validateOfficialEmail();
  const isDropdownsOk = validateDropdowns();
  const isDeclOk = validateDeclaration();

  if (!isNameOk || !isEmailOk || !isDropdownsOk || !isDeclOk) {
    console.warn("Onboarding form validation failed.");
    return false;
  }

  const name = document.getElementById("ob-fullname").value.trim();
  const container = document.getElementById("onboarding-steps-container");
  const finalBanner = document.getElementById("onboarding-final-banner");

  // Reset and reveal container
  container.innerHTML = "";
  finalBanner.style.display = "none";
  document.getElementById("onboarding-flow-card").style.display = "block";

  // DISABLE submit button during processing
  const submitBtn = document.getElementById("ob-submit-btn");
  submitBtn.disabled = true;
  submitBtn.innerHTML = "Processing Workflow...";

  /**
   * CHAINING PROMISES WITH .then() AND .catch()
   */
  createAccountStep(name)
    .then(data => sendWelcomeEmailStep(data))
    .then(data => assignLaptopStep(data))
    .then(data => {
      // Step 4: Final welcome aboard!
      finalBanner.style.display = "block";
      finalBanner.className = "success-message";
      finalBanner.innerHTML = `
        <h3 style="font-size:1.4rem; margin-bottom:8px;">🎊 Welcome aboard, ${data.candidateName}!</h3>
        <p>Your onboarding workflow is complete. Your system identity is <strong>${data.accountId}</strong>. We look forward to your day one!</p>
      `;
      finalBanner.scrollIntoView({ behavior: "smooth" });
    })
    .catch(error => {
      // Rejection handling with .catch()
      console.error("Onboarding workflow failure:", error);
      const errorDiv = document.createElement("div");
      errorDiv.className = "step-item";
      errorDiv.style.borderLeftColor = "#dc2626";
      errorDiv.style.background = "#fee2e2";
      errorDiv.style.color = "#991b1b";
      errorDiv.innerHTML = `❌ Workflow Aborted: ${error}`;
      container.appendChild(errorDiv);
    })
    .finally(() => {
      submitBtn.disabled = false;
      submitBtn.innerHTML = "Submit Onboarding Registration &rarr;";
    });

  return false;
}

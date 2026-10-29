/**
 * ==============================================================================
 * TECHNOVA HR PORTAL - DIRECTORY SCRIPT (directory.js)
 * Author: Sanket Ambre
 * Description: Fetches remote employees (async/await/try/catch), logs response.status,
 *              builds table dynamically with destructuring & createElement,
 *              dynamic search with computed property keys, shorthand object creation,
 *              spread operator object extension, row removal, and live count.
 * ==============================================================================
 */

// Active state of employees in memory
let employees = [];

// Fallback department pool for extending loaded server records
const departments = ["Engineering", "Product", "Quality Assurance", "Human Resources", "DevOps", "Finance"];

/**
 * 1. Fetch Employees from Server
 * Uses fetch, async, await, and try/catch.
 * Prints response.status to the console.
 * Extends loaded records using the Spread Operator (...employee, department).
 */
async function loadEmployees() {
  const statusContainer = document.getElementById("directory-error-message");
  const loadBtn = document.getElementById("load-emp-btn");

  statusContainer.innerHTML = "";
  loadBtn.disabled = true;
  loadBtn.innerHTML = "Fetching from server...";

  try {
    const response = await fetch("https://jsonplaceholder.typicode.com/users");

    // Print response.status in the console as required
    console.log("Employees API Response Status Code:", response.status);

    if (!response.ok) {
      throw new Error(`Server returned HTTP error status: ${response.status}`);
    }

    const rawData = await response.json();

    // Extend each loaded record with the spread operator {...employee, department}
    employees = rawData.map((emp, index) => {
      const department = departments[index % departments.length];
      return {
        ...emp, // Spread operator to copy existing employee fields
        department // Add company department field
      };
    });

    renderEmployeeTable(employees);
  } catch (error) {
    console.error("Directory fetch failed:", error);
    statusContainer.innerHTML = `<span style="color:#dc2626; font-weight:600;">Failed to load employees: ${error.message}</span>`;
  } finally {
    loadBtn.disabled = false;
    loadBtn.innerHTML = "Reload Employees";
  }
}

/**
 * 2. Render Employee Table with Loop and Destructuring
 * Populates tbody and updates total count template literal.
 */
function renderEmployeeTable(list) {
  const tbody = document.getElementById("directory-tbody");
  tbody.innerHTML = "";

  if (list.length === 0) {
    const emptyRow = document.createElement("tr");
    emptyRow.innerHTML = `<td colspan="6" style="text-align:center; padding:20px; color:#64748b;">No employees match the search filter.</td>`;
    tbody.appendChild(emptyRow);
  } else {
    // Loop over each employee record
    list.forEach(employee => {
      // Destructuring assignment (id, name, username, email, phone)
      const { id, name, username, email, phone, department } = employee;

      const row = document.createElement("tr");
      row.id = `emp-row-${id}`;

      // Cells
      const idCell = document.createElement("td");
      idCell.innerHTML = `<strong>#${id}</strong>`;
      row.appendChild(idCell);

      const nameCell = document.createElement("td");
      nameCell.innerHTML = name;
      row.appendChild(nameCell);

      const deptCell = document.createElement("td");
      deptCell.innerHTML = `<span style="background:#e0f2fe; color:#0369a1; padding:3px 8px; border-radius:4px; font-weight:600; font-size:0.85rem;">${department || "General"}</span>`;
      row.appendChild(deptCell);

      const userCell = document.createElement("td");
      userCell.innerHTML = `@${username}`;
      row.appendChild(userCell);

      const emailCell = document.createElement("td");
      emailCell.innerHTML = `<a href="mailto:${email}" style="color:var(--hr-primary-light);">${email}</a>`;
      row.appendChild(emailCell);

      const phoneCell = document.createElement("td");
      phoneCell.innerHTML = phone;
      row.appendChild(phoneCell);

      // Actions Cell with Remove Button
      const actionCell = document.createElement("td");
      const removeBtn = document.createElement("button");
      removeBtn.className = "btn-remove";
      removeBtn.innerHTML = "Remove &times;";
      removeBtn.onclick = function () {
        removeEmployee(id, row);
      };
      actionCell.appendChild(removeBtn);
      row.appendChild(actionCell);

      tbody.appendChild(row);
    });
  }

  // Update total employees with template literal
  updateTotalEmployeeCount();
}

/**
 * 3. Update Total Employee Count using Template Literal
 */
function updateTotalEmployeeCount() {
  const countEl = document.getElementById("total-employee-counter");
  // Template literal showing live total
  countEl.innerHTML = `Total employees: ${employees.length}`;
}

/**
 * 4. Remove Employee from memory and DOM using remove()
 */
function removeEmployee(id, rowElement) {
  if (confirm("Are you sure you want to remove this employee from directory?")) {
    // Delete row from DOM using element.remove()
    rowElement.remove();

    // Remove from in-memory array
    employees = employees.filter(emp => emp.id !== id);

    // Update total count
    updateTotalEmployeeCount();
    console.log(`Employee ID #${id} removed. Updated count: ${employees.length}`);
  }
}

/**
 * 5. Search with Choice using Computed Property Key
 * Constructs an object with {[field]: text} and filters.
 */
function handleSearch() {
  const searchField = document.getElementById("search-field-select").value; // "name", "email", or "username"
  const searchText = document.getElementById("search-input").value.trim().toLowerCase();

  // Object built with a computed key:
  const searchFilterObject = {
    [searchField]: searchText
  };
  console.log("Search Filter Object with Computed Key:", searchFilterObject);

  const matched = employees.filter(emp => {
    const val = (emp[searchField] || "").toLowerCase();
    return val.includes(searchFilterObject[searchField]);
  });

  renderEmployeeTable(matched);
}

/**
 * 6. Add New Employee Form Handler
 * Uses shorthand property syntax { id, name, department, ... }
 * and extends loaded record with spread operator.
 */
function handleAddEmployee(event) {
  event.preventDefault();

  const nameInput = document.getElementById("add-name");
  const deptSelect = document.getElementById("add-department");
  const emailInput = document.getElementById("add-email");
  const phoneInput = document.getElementById("add-phone");

  const name = nameInput.value.trim();
  const department = deptSelect.value;
  const email = emailInput.value.trim() || `${name.toLowerCase().replace(/\s+/g, ".")}@technova.com`;
  const phone = phoneInput.value.trim() || "1-555-0199";

  if (!name || !department) {
    alert("Please provide both employee name and department.");
    return false;
  }

  // Generate next id
  const id = employees.length > 0 ? Math.max(...employees.map(e => e.id)) + 1 : 1;
  const username = name.toLowerCase().replace(/\s+/g, "_");

  // Shorthand properties to create new employee object:
  const newEmployeeData = {
    id,
    name,
    username,
    department,
    email,
    phone
  };

  // Prepend to array
  employees.unshift(newEmployeeData);

  // Clear input fields
  nameInput.value = "";
  deptSelect.value = "";
  emailInput.value = "";
  phoneInput.value = "";

  // Re-render table
  renderEmployeeTable(employees);
  alert(`Employee "${name}" successfully registered!`);
  return false;
}

// Automatically load employees on page load
window.addEventListener("DOMContentLoaded", () => {
  loadEmployees();
});

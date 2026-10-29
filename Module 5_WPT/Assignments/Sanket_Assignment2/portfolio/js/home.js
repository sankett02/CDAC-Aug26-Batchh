/**
 * ==============================================================================
 * HOME PAGE JAVASCRIPT (home.js)
 * Author: Sanket Ambre
 * Description: Manages interactive welcome banner, light/dark mode theme switcher,
 *              skills list show/hide toggle, and async GitHub repos loader.
 * ==============================================================================
 */

// Global state variable for demo (var used intentionally to demonstrate hoisting & function scope)
/* Demonstrating var: hoisted to top of script scope with undefined value */
var pageSessionName = "Portfolio_Home_Session";

/**
 * 1. Time-based dynamic greeting (Bonus Feature)
 * Uses Date object to determine morning, afternoon, or evening.
 */
function updateTimeBasedGreeting() {
  const greetingEl = document.getElementById("time-greeting");
  if (!greetingEl) return;

  const currentHour = new Date().getHours();
  let greeting = "Welcome";

  if (currentHour < 12) {
    greeting = "Good Morning";
  } else if (currentHour < 18) {
    greeting = "Good Afternoon";
  } else {
    greeting = "Good Evening";
  }

  greetingEl.innerHTML = `${greeting}, and welcome to my space!`;
}

/**
 * 2. Welcome Box Handler
 * Reads visitor's name from input, checks for empty value,
 * and displays personalized or fallback greeting using a template literal.
 */
function displayWelcome() {
  const nameInput = document.getElementById("visitor-name-input");
  const welcomeOutput = document.getElementById("welcome-heading");

  // Read value and trim whitespace
  const visitorName = nameInput.value.trim();

  // If input is empty, show a friendly fallback message; else greet with template literal
  if (visitorName === "") {
    welcomeOutput.innerHTML = "Welcome, valued guest! Feel free to explore my work.";
  } else {
    welcomeOutput.innerHTML = `Welcome, ${visitorName}! Thrilled to have you here.`;
  }
}

/**
 * 3. Light and Dark Mode Theme Switcher
 * Toggles body styles between dark and light themes using if/else.
 * Also preserves theme preference in localStorage (Bonus).
 */
function toggleTheme() {
  const themeBtn = document.getElementById("theme-toggle-btn");
  const body = document.body;

  // Check current button label to determine next state
  if (themeBtn.innerHTML === "Dark mode") {
    // Switch to Dark Mode
    body.style.backgroundColor = "#0f172a";
    body.style.color = "#f8fafc";
    themeBtn.innerHTML = "Light mode";
    themeBtn.style.backgroundColor = "#334155";
    themeBtn.style.color = "#f8fafc";

    // Update surface containers for dark mode
    document.querySelectorAll(".hero-section, .interactive-toolbar, .subscribe-box, .about-box, .card, .repo-section, #main-nav")
      .forEach(el => {
        el.style.backgroundColor = "#1e293b";
        el.style.color = "#f8fafc";
      });

    // Save to localStorage (Bonus)
    localStorage.setItem("userTheme", "dark");
  } else {
    // Switch to Light Mode
    body.style.backgroundColor = "#f0fdfa";
    body.style.color = "#1f2937";
    themeBtn.innerHTML = "Dark mode";
    themeBtn.style.backgroundColor = "";
    themeBtn.style.color = "";

    // Reset surface containers
    document.querySelectorAll(".hero-section, .interactive-toolbar, .subscribe-box, .about-box, .card, .repo-section, #main-nav")
      .forEach(el => {
        el.style.backgroundColor = "#ffffff";
        el.style.color = "#1f2937";
      });

    // Save to localStorage (Bonus)
    localStorage.setItem("userTheme", "light");
  }
}

/**
 * 4. Restore theme from localStorage on initial page load (Bonus)
 */
function restoreSavedTheme() {
  const savedTheme = localStorage.getItem("userTheme");
  if (savedTheme === "dark") {
    toggleTheme();
  }
}

/**
 * 5. Show and Hide Skills List
 * Changes style.display property between "none" and "block",
 * and updates button text between "Hide" and "Show".
 */
function toggleSkillsList() {
  const skillsList = document.getElementById("skills-list");
  const toggleBtn = document.getElementById("skills-toggle-btn");

  if (skillsList.style.display === "none") {
    skillsList.style.display = "block";
    toggleBtn.innerHTML = "Hide Skills";
  } else {
    skillsList.style.display = "none";
    toggleBtn.innerHTML = "Show Skills";
  }
}

/**
 * 6. Asynchronous GitHub Repositories Fetcher
 * Fetches public repos from GitHub API (or fallback).
 * Uses async/await, verifies response.status, reads json,
 * and dynamically renders repo names using createElement & appendChild.
 * Handles failures by rendering error message in red.
 */
async function loadGitHubRepos() {
  const repoContainer = document.getElementById("repo-list-container");
  const errorContainer = document.getElementById("repo-error-message");
  const loadBtn = document.getElementById("load-repos-btn");

  // Reset previous state
  repoContainer.innerHTML = "";
  errorContainer.innerHTML = "";
  loadBtn.disabled = true;
  loadBtn.innerHTML = "Fetching repositories...";

  const username = "sanketambre";
  const apiUrl = `https://api.github.com/users/${username}/repos?per_page=6&sort=updated`;

  try {
    const response = await fetch(apiUrl);

    // Validate HTTP status
    if (response.status === 200) {
      const repos = await response.json();

      if (repos.length === 0) {
        repoContainer.innerHTML = "<p>No public repositories found for this account.</p>";
        return;
      }

      // Render each repo name as a dynamically created list element
      repos.forEach(repo => {
        const li = document.createElement("li");
        li.className = "repo-item";

        const title = document.createElement("strong");
        title.innerHTML = repo.name;

        const desc = document.createElement("p");
        desc.style.fontSize = "0.85rem";
        desc.style.color = "#64748b";
        desc.innerHTML = repo.description || "Portfolio project repository";

        li.appendChild(title);
        li.appendChild(desc);
        repoContainer.appendChild(li);
      });
    } else {
      // If GitHub rate limit reached (HTTP 403) or user not found, load fallback posts
      console.warn(`GitHub API returned status ${response.status}. Using placeholder fallback.`);
      await loadFallbackPosts(repoContainer);
    }
  } catch (error) {
    // Show error in red
    console.error("Fetch error:", error);
    errorContainer.style.color = "#dc2626";
    errorContainer.style.fontWeight = "bold";
    errorContainer.innerHTML = `Failed to load repositories: ${error.message}. Please check your connection.`;
  } finally {
    loadBtn.disabled = false;
    loadBtn.innerHTML = "Reload Repositories";
  }
}

/**
 * Fallback loader using jsonplaceholder posts as instructed in brief
 */
async function loadFallbackPosts(container) {
  try {
    const fallbackResponse = await fetch("https://jsonplaceholder.typicode.com/posts?_limit=5");
    if (fallbackResponse.status === 200) {
      const posts = await fallbackResponse.json();
      posts.forEach(post => {
        const li = document.createElement("li");
        li.className = "repo-item";
        li.innerHTML = `<strong>${post.title}</strong><p style="font-size:0.85rem;color:#64748b">${post.body.slice(0, 60)}...</p>`;
        container.appendChild(li);
      });
    }
  } catch (err) {
    throw new Error("Could not fetch remote projects or placeholder fallback.");
  }
}

// Initialize on page load
window.addEventListener("DOMContentLoaded", () => {
  updateTimeBasedGreeting();
  restoreSavedTheme();
});

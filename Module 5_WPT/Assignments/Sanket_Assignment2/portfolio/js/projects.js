/**
 * ==============================================================================
 * PROJECTS PAGE JAVASCRIPT (projects.js)
 * Author: Sanket Ambre
 * Description: Implements OOP classes (Project, FeaturedProject), async promise-based
 *              data loading, search/filter with arrow functions, map/reduce,
 *              DOM manipulation with destructuring, and sorting.
 * ==============================================================================
 */

/**
 * Base Project Class
 */
class Project {
  constructor(id, title, tech, description, link, demoLink = null) {
    this.id = id;
    this.title = title;
    this.tech = tech; // Array of technologies
    this.description = description;
    this.link = link;
    this.demoLink = demoLink;
  }

  // Method returning a formatted summary of the project
  getSummary() {
    return `${this.title} built with ${this.tech.join(", ")}`;
  }
}

/**
 * FeaturedProject Class extending Project with inheritance & super()
 */
class FeaturedProject extends Project {
  constructor(id, title, tech, description, link, demoLink = null, badge = "Featured") {
    super(id, title, tech, description, link, demoLink);
    this.badge = badge; // Additional badge property
  }

  // Polymorphic override or specialized method
  getBadgeInfo() {
    return `[${this.badge}] ${this.getSummary()}`;
  }
}

// Master Project Dataset (At least 5 projects instantiated via classes)
const projectData = [
  new FeaturedProject(
    1,
    "CrewConnect Maritime Management System",
    ["React", "Node.js", "Docker", "PostgreSQL"],
    "Enterprise maritime crew planning, compliance verification, and certification tracking portal.",
    "https://github.com/sanketambre/crewconnect",
    "https://crewconnect-demo.vercel.app",
    "Flagship"
  ),
  new FeaturedProject(
    2,
    "TechNova HR Operations Suite",
    ["Vanilla JavaScript", "HTML5", "CSS3", "REST APIs"],
    "Interactive portal featuring employee directories, multi-step onboarding workflows, and credential validations.",
    "https://github.com/sanketambre/technova-hr",
    "https://technova-demo.netlify.app",
    "Popular"
  ),
  new Project(
    3,
    "SimplifyIQ AI Workflow Classifier",
    ["Python", "FastAPI", "SQLite", "Tailwind CSS"],
    "AI-driven automated ticket categorization and customer enquiry triaging system.",
    "https://github.com/sanketambre/simplifyiq",
    null // demoLink intentionally omitted to test ?. and ??
  ),
  new Project(
    4,
    "Nebula Nitro Local Landing & Order Engine",
    ["HTML5", "CSS3 Flexbox", "JavaScript ES6"],
    "Interactive customer menu ordering with live cart calculation, tier discounts, and area delivery logic.",
    "https://github.com/sanketambre/nebula-nitro",
    null // demoLink intentionally omitted
  ),
  new Project(
    5,
    "Microservice E-Commerce Gateway",
    ["Java", "Spring Boot", "MySQL", "Kafka"],
    "Scalable backend architecture handling order queues, distributed transactions, and inventory reserves.",
    "https://github.com/sanketambre/ecommerce-gateway",
    "https://api-gateway-docs.internal.io"
  )
];

// Active filtered list
let currentProjectsList = [];
let isAscendingSort = true;

/**
 * 1. Pretend Server Promise Function
 * Waits 1.5 seconds with setTimeout, then resolves with projects array
 * or rejects if dataset is empty.
 */
function loadProjects() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (projectData && projectData.length > 0) {
        resolve(projectData);
      } else {
        reject(new Error("Unable to load projects: dataset is empty or server unreachable."));
      }
    }, 1500);
  });
}

/**
 * 2. Another Promise demonstration using .then() and .catch()
 * Checks fake server health/status and updates status pill in header.
 */
function checkServerStatus() {
  const statusPromise = new Promise((resolve, reject) => {
    // Simulated fast network ping
    const isServerOnline = true;
    setTimeout(() => {
      if (isServerOnline) {
        resolve({ ping: 42, server: "Asia-South1", status: "Healthy" });
      } else {
        reject("Server ping failed.");
      }
    }, 600);
  });

  // Handled with .then() and .catch() as required
  statusPromise
    .then(data => {
      console.log("Server Health Check (Promise .then):", data);
      const serverStatusEl = document.getElementById("server-status-pill");
      if (serverStatusEl) {
        serverStatusEl.innerHTML = `🟢 Server: ${data.status} (${data.ping}ms)`;
        serverStatusEl.style.color = "#15803d";
      }
    })
    .catch(err => {
      console.error("Server Health Check Error (Promise .catch):", err);
      const serverStatusEl = document.getElementById("server-status-pill");
      if (serverStatusEl) {
        serverStatusEl.innerHTML = "🔴 Server: Offline";
        serverStatusEl.style.color = "#dc2626";
      }
    });
}

/**
 * 3. Primary Async/Await Handler for Loading Projects
 * Displays "Loading projects..." first, handles promise with try/catch.
 */
async function initializeProjectsPage() {
  const loadingIndicator = document.getElementById("loading-indicator");
  const tableBody = document.getElementById("projects-tbody");

  try {
    loadingIndicator.style.display = "block";
    loadingIndicator.innerHTML = "<em>⏳ Loading projects from server, please wait...</em>";

    // Await pretend server promise
    const loadedData = await loadProjects();
    currentProjectsList = [...loadedData];

    // Populate dropdown tech options using map
    populateTechDropdown(loadedData);

    // Compute metrics with reduce and map
    computeProjectMetrics(loadedData);

    // Render table rows
    renderProjectsTable(currentProjectsList);

    // Render top 2 featured cards
    renderFeaturedCards(loadedData);

    loadingIndicator.style.display = "none";
  } catch (error) {
    loadingIndicator.style.display = "block";
    loadingIndicator.style.color = "#dc2626";
    loadingIndicator.innerHTML = `⚠️ Error: ${error.message}`;
  }
}

/**
 * 4. Render Table with Loop, Destructuring, and Nullish Coalescing (?.) and (??)
 */
function renderProjectsTable(projects) {
  const tbody = document.getElementById("projects-tbody");
  const counterEl = document.getElementById("projects-count-status");
  tbody.innerHTML = "";

  // Template literal showing N of M projects
  counterEl.innerHTML = `Showing ${projects.length} of ${projectData.length} projects`;

  if (projects.length === 0) {
    const emptyRow = document.createElement("tr");
    const emptyCell = document.createElement("td");
    emptyCell.colSpan = 5;
    emptyCell.style.textAlign = "center";
    emptyCell.style.padding = "20px";
    emptyCell.innerHTML = "No matching projects found.";
    emptyRow.appendChild(emptyCell);
    tbody.appendChild(emptyRow);
    return;
  }

  // Loop through every project
  projects.forEach(project => {
    // Destructuring assignment
    const { id, title, tech, description, link, demoLink } = project;

    const row = document.createElement("tr");

    // Title Cell
    const titleCell = document.createElement("td");
    titleCell.innerHTML = `<strong>${title}</strong>`;
    row.appendChild(titleCell);

    // Tech Used Cell
    const techCell = document.createElement("td");
    tech.forEach(t => {
      const span = document.createElement("span");
      span.className = "tech-tag";
      span.innerHTML = t;
      techCell.appendChild(span);
    });
    row.appendChild(techCell);

    // Description Cell
    const descCell = document.createElement("td");
    descCell.innerHTML = description;
    row.appendChild(descCell);

    // Code Link Cell
    const linkCell = document.createElement("td");
    linkCell.innerHTML = `<a href="${link}" target="_blank" rel="noopener" style="color:var(--primary-color); font-weight:600;">Repository &rarr;</a>`;
    row.appendChild(linkCell);

    // Demo Link Cell using Optional Chaining (?.) and Nullish Coalescing (??)
    const demoCell = document.createElement("td");
    const demoUrl = project?.demoLink ?? null;

    if (demoUrl) {
      demoCell.innerHTML = `<a href="${demoUrl}" target="_blank" rel="noopener" style="color:#059669; font-weight:600;">Live Demo &nearr;</a>`;
    } else {
      demoCell.innerHTML = `<span style="color:#94a3b8; font-style:italic;">${project?.demoLink ?? "Not available"}</span>`;
    }
    row.appendChild(demoCell);

    tbody.appendChild(row);
  });
}

/**
 * 5. Render Top Two Featured Cards dynamically with badges
 */
function renderFeaturedCards(projects) {
  const cardsContainer = document.getElementById("featured-cards-container");
  cardsContainer.innerHTML = "";

  // Filter top two featured projects
  const featured = projects.filter(p => p instanceof FeaturedProject).slice(0, 2);

  featured.forEach(item => {
    const { title, description, link, badge } = item;

    const card = document.createElement("div");
    card.className = "card";
    card.style.position = "relative";
    card.style.flex = "1";

    // Badge created dynamically
    const badgeSpan = document.createElement("span");
    badgeSpan.className = "badge-new";
    badgeSpan.innerHTML = badge;
    card.appendChild(badgeSpan);

    const icon = document.createElement("span");
    icon.className = "card-icon";
    icon.innerHTML = "&#9733;";
    card.appendChild(icon);

    const h3 = document.createElement("h3");
    h3.innerHTML = title;
    card.appendChild(h3);

    const p = document.createElement("p");
    p.style.color = "var(--text-muted)";
    p.style.marginBottom = "14px";
    p.innerHTML = description;
    card.appendChild(p);

    const a = document.createElement("a");
    a.href = link;
    a.target = "_blank";
    a.rel = "noopener";
    a.style.color = "var(--primary-color)";
    a.style.fontWeight = "600";
    a.innerHTML = "View Source Code &rarr;";
    card.appendChild(a);

    cardsContainer.appendChild(card);
  });
}

/**
 * 6. Search and Filter with Array.filter() and Arrow Functions
 */
function applyFilters() {
  const searchInput = document.getElementById("search-title-input").value.trim().toLowerCase();
  const techSelect = document.getElementById("filter-tech-select").value;

  // Filter using arrow functions
  const filtered = projectData.filter(project => {
    const matchesTitle = project.title.toLowerCase().includes(searchInput);
    const matchesTech = techSelect === "" || project.tech.includes(techSelect);
    return matchesTitle && matchesTech;
  });

  currentProjectsList = filtered;
  renderProjectsTable(currentProjectsList);
}

/**
 * 7. Populating Technology Dropdown dynamically using map
 */
function populateTechDropdown(projects) {
  const select = document.getElementById("filter-tech-select");
  // Use map to extract tech arrays and flat/filter for unique values
  const allTechs = projects.map(p => p.tech).flat();
  const uniqueTechs = [...new Set(allTechs)];

  uniqueTechs.forEach(tech => {
    const option = document.createElement("option");
    option.value = tech;
    option.innerHTML = tech;
    select.appendChild(option);
  });
}

/**
 * 8. Using map and reduce to compute project statistics
 * - map: builds list of project titles
 * - reduce: counts the total technologies referenced across all projects
 */
function computeProjectMetrics(projects) {
  // Use map once
  const titleList = projects.map(p => p.title);
  console.log("Projects Map Demo (Titles Array):", titleList);

  // Use reduce once to aggregate total technology mentions
  const totalTechUsedCount = projects.reduce((acc, curr) => acc + curr.tech.length, 0);
  console.log("Projects Reduce Demo (Total Tech Count):", totalTechUsedCount);

  const statsContainer = document.getElementById("project-stats-info");
  if (statsContainer) {
    statsContainer.innerHTML = `<strong>Metrics:</strong> ${projects.length} Total Projects Cataloged | ${totalTechUsedCount} Total Tech Stacks Deployed`;
  }
}

/**
 * 9. Bonus Feature: Sort projects table by title using sort()
 */
function toggleSortByTitle() {
  const sortBtn = document.getElementById("sort-title-btn");
  isAscendingSort = !isAscendingSort;

  currentProjectsList.sort((a, b) => {
    if (a.title.toLowerCase() < b.title.toLowerCase()) return isAscendingSort ? -1 : 1;
    if (a.title.toLowerCase() > b.title.toLowerCase()) return isAscendingSort ? 1 : -1;
    return 0;
  });

  sortBtn.innerHTML = isAscendingSort ? "Sort Title (A-Z) &uarr;" : "Sort Title (Z-A) &darr;";
  renderProjectsTable(currentProjectsList);
}

// Kick off initialization and secondary promise when DOM loads
window.addEventListener("DOMContentLoaded", () => {
  initializeProjectsPage();
  checkServerStatus();
});

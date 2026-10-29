
const button = document.querySelector("#loadBtn");
const result = document.querySelector("#result");

button.addEventListener("click", async () => {
  result.textContent = "Loading...";

  try {
    const response = await fetch(
      "https://jsonplaceholder.typicode.com/users/1"
    );

    if (!response.ok) {
      throw new Error(`HTTP error: ${response.status}`);
    }

    const data = await response.json();

    result.textContent = JSON.stringify(data, null, 2);
  } catch (error) {
    result.textContent = `Request failed: ${error.message}`;
  }
});

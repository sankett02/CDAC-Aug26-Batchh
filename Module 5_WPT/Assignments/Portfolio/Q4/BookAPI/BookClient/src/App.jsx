
import { useState } from "react";
import "./App.css";

function App() {
  const [name, setName] = useState("");
  const [author, setAuthor] = useState("");
  const [price, setPrice] = useState("");
  const [books, setBooks] = useState([]);
  const [message, setMessage] = useState("");

  async function addBook(event) {
    event.preventDefault();
    setMessage("");

    try {
      const response = await fetch("http://localhost:5000/books", {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({
          name: name,
          author: author,
          price: price
        })
      });

      const data = await response.json();

      if (!response.ok) {
        throw new Error(data.error || "Unable to add book.");
      }

      // Add the API response to the displayed list
      setBooks((previousBooks) => [...previousBooks, data]);

      // Clear the form
      setName("");
      setAuthor("");
      setPrice("");
      setMessage("Book added successfully!");
    } catch (error) {
      setMessage(error.message || "Cannot connect to the API.");
    }
  }

  return (
    <div className="container">
      <h1>Book Management</h1>

      <form onSubmit={addBook}>
        <label>Book Name</label>
        <input
          type="text"
          value={name}
          onChange={(e) => setName(e.target.value)}
          required
        />

        <label>Author</label>
        <input
          type="text"
          value={author}
          onChange={(e) => setAuthor(e.target.value)}
          required
        />

        <label>Price</label>
        <input
          type="number"
          min="0"
          step="any"
          value={price}
          onChange={(e) => setPrice(e.target.value)}
          required
        />

        <button type="submit">ADD</button>
      </form>

      <p>{message}</p>

      <h2>Book Information</h2>

      {books.map((book) => (
        <div className="book-card" key={book.Id}>
          <p><strong>Book ID:</strong> {book.Id}</p>
          <p><strong>Book Name:</strong> {book.Name}</p>
          <p><strong>Author:</strong> {book.Author}</p>
          <p><strong>Price:</strong> {book.Price}</p>
        </div>
      ))}
    </div>
  );
}

export default App;

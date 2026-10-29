
const { createServer } = require("node:http");

const server = createServer((req, res) => {
  res.writeHead(200, {
    "Content-Type": "text/plain"
  });

  if (req.url === "/") {
    res.end("Home page");
  } else if (req.url === "/about") {
    res.end("About page");
  } else if (req.url === "/contact") {
    res.end("Contact page");
  } else {
    res.writeHead(404);
    res.end("Route not found");
  }
});

server.listen(5000, () => {
  console.log("Server running on port 5000");
});

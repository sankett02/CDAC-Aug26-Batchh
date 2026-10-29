import { createPool } from "mysql2/promise";

const db = createPool({
    host: "localhost",
    port: 3306,
    user: "root",
    password: "Sanket@2005",
    database: "productdb",
    connectionLimit: 10
});

export default db;
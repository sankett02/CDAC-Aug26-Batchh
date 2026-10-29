
import { useState } from "react";

function Addition() {
    const [num1, setNum1] = useState("");
    const [num2, setNum2] = useState("");

    const sum = Number(num1) + Number(num2);

    return (
        <div>
            <h2>Addition Calculator</h2>

            <label>First Number: </label>
            <input
                type="number"
                value={num1}
                onChange={(e) => setNum1(e.target.value)}
            />

            <br /><br />

            <label>Second Number: </label>
            <input
                type="number"
                value={num2}
                onChange={(e) => setNum2(e.target.value)}
            />

            <h3>Sum: {sum}</h3>
        </div>
    );
}

export default Addition;

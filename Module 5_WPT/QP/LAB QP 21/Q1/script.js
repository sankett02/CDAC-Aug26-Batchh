
let participants = [];

// STEP 1: Calculate training cost
function calculateCost() {
    let seminar = document.getElementById("seminar").value;

    let selectedLevel = document.querySelector(
        'input[name="level"]:checked'
    );

    if (seminar === "" || !selectedLevel) {
        alert("Please select seminar and level");
        return;
    }

    let level = selectedLevel.value;
    let cost = 0;

    if (seminar === "SOA") {
        if (level === "Introductory") cost = 2500;
        else if (level === "Intermediate") cost = 3500;
        else if (level === "Advanced") cost = 6000;

    } else if (seminar === "Design Patterns") {
        if (level === "Introductory") cost = 4000;
        else if (level === "Intermediate") cost = 5500;
        else if (level === "Advanced") cost = 8000;

    } else if (seminar === "Business Intelligence") {
        if (level === "Introductory") cost = 5000;
        else if (level === "Intermediate") cost = 7000;
        else if (level === "Advanced") cost = 10000;
    }

    document.getElementById("cost").value = cost;
}


// STEP 2: Validate and save participant details
document.getElementById("seminarForm").addEventListener(
    "submit", function(event) {

        event.preventDefault();

        let title = document.getElementById("title").value;
        let firstName = document.getElementById("firstName").value.trim();
        let lastName = document.getElementById("lastName").value.trim();
        let email = document.getElementById("email").value.trim();
        let confirmEmail =
            document.getElementById("confirmEmail").value.trim();

        // Check email format
        if (!document.getElementById("email").checkValidity() ||
            !document.getElementById("confirmEmail").checkValidity()) {
            alert("Please enter valid email addresses");
            return;
        }

        // Check whether both emails match
        if (email !== confirmEmail) {
            alert("Email IDs do not match");
            return;
        }

        // Check that a seminar and level are selected
        let seminar = document.getElementById("seminar").value;

        let selectedLevel = document.querySelector(
            'input[name="level"]:checked'
        );

        if (seminar === "" || !selectedLevel) {
            alert("Please select seminar and level");
            return;
        }

        // Calculate the cost for the current selections
        calculateCost();

        let cost = document.getElementById("cost").value;

        if (cost === "") {
            alert("Please calculate the training cost");
            return;
        }

        // Join title, first name and last name
        let fullName = title + " " + firstName + " " + lastName;

        // Create one participant record
        let participant = {
            name: fullName,
            email: email,
            seminar: seminar,
            level: selectedLevel.value,
            cost: cost
        };

        // Save the participant in the array
        participants.push(participant);

        alert("All data entered correctly");

        // Clear the form for the next participant
        document.getElementById("seminarForm").reset();
        document.getElementById("cost").value = "";
    }
);


// STEP 3: Display all participants in a separate window
function displayDetails() {

    if (participants.length === 0) {
        alert("No participants registered yet");
        return;
    }

    let output = `
        <!DOCTYPE html>
        <html>
        <head>
            <title>Participant Details</title>
            <style>
                body {
                    font-family: Arial, sans-serif;
                    margin: 25px;
                }
                table {
                    border-collapse: collapse;
                    width: 100%;
                }
                th, td {
                    border: 1px solid black;
                    padding: 10px;
                    text-align: left;
                }
                th {
                    background-color: #dddddd;
                }
            </style>
        </head>
        <body>
            <h2>Seminar Participant Details</h2>
            <table>
                <tr>
                    <th>Sr. No.</th>
                    <th>Participant Name</th>
                    <th>Email ID</th>
                    <th>Seminar</th>
                    <th>Level</th>
                    <th>Cost (Rs.)</th>
                </tr>
    `;

    participants.forEach(function(p, index) {
        output += `
            <tr>
                <td>${index + 1}</td>
                <td>${p.name}</td>
                <td>${p.email}</td>
                <td>${p.seminar}</td>
                <td>${p.level}</td>
                <td>${p.cost}</td>
            </tr>
        `;
    });

    output += `
            </table>
        </body>
        </html>
    `;

    let newWindow = window.open("", "_blank");

    if (newWindow) {
        newWindow.document.write(output);
        newWindow.document.close();
    } else {
        alert("Please allow pop-ups in your browser");
    }
}

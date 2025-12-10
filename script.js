document.addEventListener("DOMContentLoaded", () => {
    const form = document.getElementById("patient-form");
    const tableBody = document.querySelector("#patients-table tbody");

    if (!form || !tableBody) {
        // Safety check
        return;
    }

    form.addEventListener("submit", (event) => {
        // Stop the normal form submit (no page reload)
        event.preventDefault();

        // Read values from the form
        const id = document.getElementById("patient-id").value.trim();
        const name = document.getElementById("patient-name").value.trim();
        const age = document.getElementById("patient-age").value.trim();
        const disease = document.getElementById("patient-disease").value.trim();
        const doctor = document.getElementById("patient-doctor").value.trim();

        // Very basic validation
        if (!id || !name || !age || !disease || !doctor) {
            alert("Please fill all fields.");
            return;
        }

        // Create a new row
        const row = document.createElement("tr");
        row.innerHTML = `
            <td>${id}</td>
            <td>${name}</td>
            <td>${age}</td>
            <td>${disease}</td>
            <td>${doctor}</td>
        `;

        // Add row to table
        tableBody.appendChild(row);

        // Clear the form
        form.reset();
    });
});
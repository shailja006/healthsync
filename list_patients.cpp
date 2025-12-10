#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // Required HTML header
    cout << "Content-type: text/html\r\n\r\n";

    // Start HTML Page
    cout << "<html><head><title>All Patients</title>";
    cout << "<style>"
            "table { width: 80%; margin: auto; border-collapse: collapse; font-size: 18px; }"
            "th, td { border: 1px solid #333; padding: 10px; text-align: left; }"
            "th { background-color: #1e90ff; color: white; }"
            "h2 { text-align: center; }"
            "a { display: block; text-align: center; margin-top: 20px; font-size: 20px; }"
         "</style>";
    cout << "</head><body>";

    cout << "<h2>Stored Patient Records</h2>";
    cout << "<table>";
    cout << "<tr><th>ID</th><th>Name</th><th>Age</th><th>Disease</th><th>Doctor</th></tr>";

    ifstream fin("C:\\xampp\\cgi-bin\\patient.txt");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string id, name, age, disease, doctor;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, disease, ',');
        getline(ss, doctor, ',');

        cout << "<tr>";
        cout << "<td>" << id << "</td>";
        cout << "<td>" << name << "</td>";
        cout << "<td>" << age << "</td>";
        cout << "<td>" << disease << "</td>";
        cout << "<td>" << doctor << "</td>";
        cout << "</tr>";
    }

    cout << "</table>";
    cout << "<a href='/healthsync/patients.html'>Back</a>";
    cout << "</body></html>";

    return 0;
}
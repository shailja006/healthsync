#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // CGI header
    cout << "Content-type: text/html\r\n\r\n";

    ifstream fin("C:\\xampp\\cgi-bin\\patient.txt");
    if (!fin) {
        // If file can't be opened, just return nothing
        return 0;
    }

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

    return 0;
}
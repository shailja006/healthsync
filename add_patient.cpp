#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// URL Decoder helper
string decode(string s) {
    string out;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '+') out += ' ';
        else if (s[i] == '%' && i + 2 < (int)s.size()) {
            string hex = s.substr(i+1, 2);
            char ch = (char) strtol(hex.c_str(), nullptr, 16);
            out += ch;
            i += 2;
        } else out += s[i];
    }
    return out;
}

// extract value from query string: key=value&key2=value2
string getValue(string qs, string key) {
    string findKey = key + "=";
    int start = qs.find(findKey);
    if (start == -1) return "";
    start += findKey.size();
    int end = qs.find("&", start);
    string val = qs.substr(start, (end == -1 ? qs.size() : end) - start);
    return decode(val);
}

int main() {
    // Tell browser this is HTML
    cout << "Content-type: text/html\r\n\r\n";

    // Read QUERY_STRING (for GET method)
    char* qs_c = getenv("QUERY_STRING");
    string qs = qs_c ? string(qs_c) : "";

    // Get form values
    string id      = getValue(qs, "patient-id");
    string name    = getValue(qs, "patient-name");
    string age     = getValue(qs, "patient-age");
    string disease = getValue(qs, "patient-disease");
    string doctor  = getValue(qs, "patient-doctor");

    // Append to patient.txt (path inside cgi-bin)
    ofstream fout("C:\\xampp\\cgi-bin\\patient.txt", ios::app);
    if (!fout) {
        cout << "<h2>Could not open patient.txt for writing.</h2>";
        return 0;
    }

    fout << id << "," << name << "," << age << "," << disease << "," << doctor << "\n";
    fout.close();

    // Show success HTML
    cout << "<html><body>";
    cout << "<h2>Patient Added Successfully!</h2>";
    cout << "<p>ID: " << id << "</p>";
    cout << "<p>Name: " << name << "</p>";
    cout << "<p>Age: " << age << "</p>";
    cout << "<p>Disease: " << disease << "</p>";
    cout << "<p>Assigned Doctor: " << doctor << "</p>";
    cout << "<a href='/healthsync/patients.html'>Back to Patient Module</a>";
    cout << "</body></html>";

    return 0;
}
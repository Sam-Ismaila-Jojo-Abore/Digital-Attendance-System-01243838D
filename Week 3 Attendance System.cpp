#include <iostream>
#include <fstream>
using namespace std;

// Function declarations
void markAttendance();
void viewAttendanceReport();

int main() {
    int choice;

    do {
        cout << "===== Attendance System =====\n";
        cout << "1. Mark Attendance\n";
        cout << "2. View Report\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                markAttendance();
                break;
            case 2:
                viewAttendanceReport();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}

// Function to mark attendance
void markAttendance() {
    string index, status;

    ofstream file("attendance.txt", ios::app);

    cin.ignore(); // clear buffer

    cout << "Enter student index number: ";
    getline(cin, index);

    cout << "Enter attendance (P = Present, A = Absent, L = Late): ";
    getline(cin, status);

    file << index << " - " << status << endl;
    file.close();

    cout << "Attendance recorded successfully!\n\n";
}

// Function to view report
void viewAttendanceReport() {
    ifstream file("attendance.txt");
    string line;
    int present = 0, absent = 0, late = 0;

    cout << "\n--- Attendance Report ---\n";

    while (getline(file, line)) {
        cout << line << endl;

        if (line.find("P") != string::npos)
            present++;
        else if (line.find("A") != string::npos)
            absent++;
        else if (line.find("L") != string::npos)
            late++;
    }

    cout << "\nSummary:\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl << endl;

    file.close();
}

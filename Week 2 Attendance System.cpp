#include <iostream>
#include <vector>
using namespace std;

// Student structure
struct Student {
    string indexNumber;
    string name;
};

// Session structure
struct Session {
    string courseCode;
    string date;
    string startTime;
    int duration; // in minutes
};

vector<Student> students;
vector<Session> sessions;

// Register student
void registerStudent() {
    Student s;
    cout << "Enter Index Number: ";
    cin >> s.indexNumber;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    students.push_back(s);
    cout << "Student registered successfully!\n";
}

// View students
void viewStudents() {
    cout << "\n--- REGISTERED STUDENTS ---\n";

    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". "
             << students[i].indexNumber << " - "
             << students[i].name << endl;
    }
}

// Create session
void createSession() {
    Session s;

    cin.ignore();

    cout << "Enter Course Code: ";
    getline(cin, s.courseCode);

    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, s.date);

    cout << "Enter Start Time (HH:MM): ";
    getline(cin, s.startTime);

    cout << "Enter Duration (minutes): ";
    cin >> s.duration;

    sessions.push_back(s);

    cout << "Session created successfully!\n";
}

// View sessions
void viewSessions() {
    cout << "\n--- SESSIONS ---\n";

    if (sessions.empty()) {
        cout << "No sessions available!\n";
        return;
    }

    for (int i = 0; i < sessions.size(); i++) {
        cout << i + 1 << ". "
             << sessions[i].courseCode << " | "
             << sessions[i].date << " | "
             << sessions[i].startTime << " | "
             << sessions[i].duration << " mins\n";
    }
}

// Main
int main() {
    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Session\n";
        cout << "4. View Sessions\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            createSession();
            break;
        case 4:
            viewSessions();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}


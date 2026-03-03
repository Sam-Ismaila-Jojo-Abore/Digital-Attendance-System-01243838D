#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Student class
class Student {
public:
    string name;
    string id;
};

// Vector to store students
vector<Student> students;

// Save students to file
void saveStudents() {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error saving file!\n";
        return;
    }

    for (size_t i = 0; i < students.size(); i++) {
        file << students[i].name << "," << students[i].id << "\n";
    }

    file.close();
    cout << "Saved successfully!\n";
}

// Load students from file
void loadStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No existing file found. Starting fresh.\n";
        return;
    }

    students.clear(); // prevent duplicates

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        Student s;
        if (getline(ss, s.name, ',') && getline(ss, s.id)) {
            students.push_back(s);
        }
    }

    file.close();
}

// Add a new student
void addStudent() {
    Student s;
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter student ID: ";
    getline(cin, s.id);

    students.push_back(s);
    cout << "Student added successfully!\n";
}

// View all students
void viewStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Name: " << students[i].name << " | ID: " << students[i].id << "\n";
    }
    cout << "--------------------\n";
}

int main() {
    loadStudents();

    string input;
    int choice = -1;

    do {
        cout << "\n=== STUDENT SYSTEM ===\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Save\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        getline(cin, input);
        stringstream ss(input);
        ss >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: saveStudents(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    saveStudents(); // auto-save before exit
    return 0;
}

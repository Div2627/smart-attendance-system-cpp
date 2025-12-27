#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int totalClasses;
    int attendedClasses;
};

// Function declarations
void addStudent(Student students[], int &count);
void markAttendance(Student students[], int count);
void displayAttendance(Student students[], int count);

int main() {
    Student students[100];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Smart Attendance System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Display Attendance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                markAttendance(students, count);
                break;
            case 3:
                displayAttendance(students, count);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Add student
void addStudent(Student students[], int &count) {
    cout << "Enter Student ID: ";
    cin >> students[count].id;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, students[count].name);

    students[count].totalClasses = 0;
    students[count].attendedClasses = 0;

    count++;
    cout << "Student added successfully!\n";
}

// Mark attendance
void markAttendance(Student students[], int count) {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            char status;
            cout << "Enter attendance (P = Present, A = Absent): ";
            cin >> status;

            students[i].totalClasses++;

            if (status == 'P' || status == 'p') {
                students[i].attendedClasses++;
            }

            cout << "Attendance marked successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

// Display attendance
void displayAttendance(Student students[], int count) {
    if (count == 0) {
        cout << "No students available.\n";
        return;
    }

    cout << "\n--- Attendance Report ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Attended: " << students[i].attendedClasses
             << ", Total: " << students[i].totalClasses << endl;
    }
}

#include <iostream>
#include <string>
using namespace std;

// Student structure
struct Student {
    string rollNo;   // Earlier int rollNo was used, but string supports 25scs1003005571
    string name;     // Earlier cin >> name was used, but getline supports full name
    string age;
    string course;
    string marks;
};

// Array to store student records
Student students[100];

// Counts total students added
int studentCount = 0;

// Function to show menu
void showMenu() {
    cout << "\n==============================\n";
    cout << "     STUDENT RECORD SYSTEM\n";
    cout << "==============================\n";
    cout << "1. Add Student Record\n";
    cout << "2. Display All Records\n";
    cout << "3. Search Student Record\n";
    cout << "4. Update Student Record\n";
    cout << "5. Delete Student Record\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Function to check duplicate roll number
bool isDuplicateRollNo(string rollNo) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            return true;
        }
    }
    return false;
}

// Function to add student record
void addStudent() {
    if (studentCount >= 100) {
        cout << "Student record limit reached.\n";
        return;
    }

    string rollNo;

    cout << "\nEnter roll number: ";
    getline(cin, rollNo);

    if (isDuplicateRollNo(rollNo)) {
        cout << "\nA student with this roll number already exists.\n";
        return;
    }

    students[studentCount].rollNo = rollNo;

    cout << "Enter full name: ";
    getline(cin, students[studentCount].name);

    cout << "Enter age: ";
    getline(cin, students[studentCount].age);

    cout << "Enter course: ";
    getline(cin, students[studentCount].course);

    cout << "Enter marks: ";
    getline(cin, students[studentCount].marks);

    studentCount++;

    cout << "\nStudent record added successfully.\n";
}

// Function to display all student records
void displayStudents() {
    if (studentCount == 0) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n===== All Student Records =====\n";

    for (int i = 0; i < studentCount; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Marks: " << students[i].marks << endl;
    }
}

// Function to search student by roll number
void searchStudent() {
    if (studentCount == 0) {
        cout << "\nNo student records found.\n";
        return;
    }

    string searchRollNo;
    bool found = false;

    cout << "\nEnter roll number to search: ";
    getline(cin, searchRollNo);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == searchRollNo) {
            cout << "\n===== Student Found =====\n";
            cout << "Roll Number: " << students[i].rollNo << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Marks: " << students[i].marks << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent record not found.\n";
    }
}

int main() {
    string choice;

    do {
        showMenu();
        getline(cin, choice);

        // Fix: if user presses Enter without typing anything, show menu again
        if (choice == "") {
            continue;
        }

        if (choice == "1") {
            addStudent();
        }
        else if (choice == "2") {
            displayStudents();
        }
        else if (choice == "3") {
            searchStudent();
        }
        else if (choice == "4") {
            cout << "Update Student feature coming soon.\n";
        }
        else if (choice == "5") {
            cout << "Delete Student feature coming soon.\n";
        }
        else if (choice == "6") {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != "6");

    return 0;
}
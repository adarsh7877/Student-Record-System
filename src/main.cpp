#include <iostream>
using namespace std;

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

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Add Student feature coming soon.\n";
                break;

            case 2:
                cout << "Display Records feature coming soon.\n";
                break;

            case 3:
                cout << "Search Student feature coming soon.\n";
                break;

            case 4:
                cout << "Update Student feature coming soon.\n";
                break;

            case 5:
                cout << "Delete Student feature coming soon.\n";
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while(choice != 6);

    return 0;
}
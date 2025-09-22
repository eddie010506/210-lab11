#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// this is a code that checks attendance based on time 
//and how many times they have attended thru out the semester
//time stamp of check in time
struct AttendanceRecord {
    time_t checkintime;
};
//this is for storing students
struct Student {
    string name;
    int StudentID;
    vector<AttendanceRecord> checkin;
    // each student has its own dynamic array, so using vector

};

//function prototypes
void showmenu();
//adding student
void addStudent(vector<Student>& roster, const string& name, int id);
//record check in
void checkInStudent(vector<Student>& roster, int id);
//print the roster
void printRoster(const vector<Student>& roster);

int main() {
    vector<Student> courseRoster;
    int choice = 0;

    // main program loop. it will continue until the user chooses to exit.
    while (choice != 4) {
        showmenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Check for valid integer input
        if (cin.fail()) {
            cout << "\nInvalid input. Please enter a number.\n" << endl;
            cin.clear(); // Clear the error flag
            // Discard the invalid input from the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and show the menu again
        }

        switch (choice) {
            case 1: { // Add a new student
                string name;
                int id;
                cout << "Enter student name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;

                 // check for valid ID input
                if (cin.fail()) {
                    cout << "\nInvalid ID. Please enter a number.\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    addStudent(courseRoster, name, id);
                }
                break;
            }
            case 2: { // check in a student
                int id;
                cout << "Enter student ID to check in: ";
                cin >> id;

                 // check for valid ID input
                if (cin.fail()) {
                    cout << "\nInvalid ID. Please enter a number.\n" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    checkInStudent(courseRoster, id);
                }
                break;
            }
            case 3: { // print the roster
                printRoster(courseRoster);
                break;
            }
            case 4: { // exit
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            default: { // handle invalid menu choices
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
        cout << endl; // add a newline for better spacing
    }

    // no need to manually deallocate memory for the vectors.

    return 0;

}
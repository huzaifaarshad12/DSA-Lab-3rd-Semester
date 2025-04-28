#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayVectorInfo(const vector<string>& vec) {
    cout << "Current size: " << vec.size() << "\n";
    cout << "Current capacity: " << vec.capacity() << "\n";
}

void addString(vector<string>& vec) {
    string newString;
    cout << "Enter a string to add: ";
    getline(cin, newString);
    vec.push_back(newString);
    cout << "String added.\n";
    displayVectorInfo(vec);
}

void removeString(vector<string>& vec) {
    if (vec.empty()) {
        cout << "The vector is empty, nothing to remove.\n";
    } else {
        vec.pop_back();
        cout << "Last string removed.\n";
        displayVectorInfo(vec);
    }
}

int main() {
    vector<string> myStrings;
    int choice;

    do {
        cout << "\n1. Add a string\n2. Remove last string\n3. Display size and capacity\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                addString(myStrings);
                break;
            case 2:
                removeString(myStrings);
                break;
            case 3:
                displayVectorInfo(myStrings);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

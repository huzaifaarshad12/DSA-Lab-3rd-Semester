#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> strVec;
    string input;
    char choice;

    do {
        cout << "Enter a string to add (or type 'remove' to remove last string): ";
        cin >> input;
        if (input == "remove") {
            if (!strVec.empty()) {
                strVec.pop_back();
                cout << "Removed last string." << endl;
            } else {
                cout << "Vector is empty." << endl;
            }
        } else {
            strVec.push_back(input);
        }
        cout << "Current size: " << strVec.size() << ", Capacity: " << strVec.capacity() << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y');

    return 0;
}
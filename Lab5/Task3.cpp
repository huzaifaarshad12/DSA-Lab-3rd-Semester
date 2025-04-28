#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector = {10, 20, 30, 40, 50}; // Example usage
    int target;
    
    cout << "Enter an integer to search for: ";
    cin >> target;

    bool found = false;
    for (size_t i = 0; i < myVector.size(); ++i) {
        if (myVector[i] == target) {
            cout << "Integer " << target << " found at index " << i << "." << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Integer " << target << " is not present in the vector." << endl;
    }

    return 0;
}

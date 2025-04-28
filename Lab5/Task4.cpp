#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator>  

using namespace std;

void displayVector(const vector<int>& vec) {
    for (const int& num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void reverseVector(vector<int>& vec) {
    reverse(vec.begin(), vec.end());
    cout << "Reversed vector: ";
    displayVector(vec);
}

void sortVector(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    displayVector(vec);
}

void removeDuplicates(vector<int>& vec) {

    sort(vec.begin(), vec.end());
    
    auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    cout << "Vector after removing duplicates: ";
    displayVector(vec);
}

int main() {
    vector<int> myVector = {5, 3, 8, 5, 1, 3, 2, 8, 9, 7};

    cout << "Original vector: ";
    displayVector(myVector);

    reverseVector(myVector);
    
    sortVector(myVector);
    
    
    removeDuplicates(myVector);

    return 0;
}

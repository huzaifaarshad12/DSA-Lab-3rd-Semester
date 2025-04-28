#include <iostream>
#include <vector>
#include <algorithm> // For std

using namespace std;

int main() {
    vector<int> intVec = {20, 30, 40, 50, 60};

    int searchValue;
    cout << "Enter an integer to search: ";
    cin >> searchValue;
    auto it = find(intVec.begin(), intVec.end(), searchValue);

    if (it != intVec.end()) {
        size_t index = distance(intVec.begin(), it);
        cout<<"Integer "<<searchValue<<" found at index: "<<index<<endl;
    } else 
    {
        cout<<"Integer "<<searchValue<<" is not present in the vector."<<endl;
    }
    return 0;
}
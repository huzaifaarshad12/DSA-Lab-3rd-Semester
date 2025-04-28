#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector;

    for (int i = 0; i < 100; ++i) {
        myVector.push_back(i);  // Insert the integer
        cout << "After inserting " << i << ": ";
        cout << "Size = " << myVector.size() << ", ";
        cout << "Capacity = " << myVector.capacity() << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> intVec = {9,8,4,6,1,0};
    reverse(intVec.begin(), intVec.end());
    sort(intVec.begin(), intVec.end());
    auto last = unique(intVec.begin(), intVec.end());
    intVec.erase(last, intVec.end());

    for (int num : intVec) 
    {
        cout << num << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> intVec;
    for (int i = 0; i < 100; i++)
    {
        intVec.push_back(i);
        cout<<"Size: "<<intVec.size()<<", Capacity: "<<intVec.capacity()<<endl;
    }
    return 0;
}
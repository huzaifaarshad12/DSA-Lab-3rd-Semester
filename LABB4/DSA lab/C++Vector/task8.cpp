#include <iostream>
using namespace std;

template<typename T>
class ArrayList {
private:
   T* data;
   size_t size;
   size_t capacity;

public:
ArrayList() : size(0), capacity(2) { data = new T[capacity]; }
~ArrayList() { delete[] data; }

   void PushBack(T value) {
        if (size == capacity) {
           capacity = static_cast<size_t>(capacity * 1.5);
           T* newData = new T[capacity];
           for (size_t i = 0; i < size; ++i) newData[i] = data[i];
           delete[] data;
           data = newData;
        }
       data[size++] = value;
   }

T operator[](int index) const { return data[index]; }
T& operator[](int index) { return data[index]; }
friend ostream& operator<<(ostream& out, const ArrayList& list) {
    for (size_t i = 0; i < list.size; ++i)
        out << list.data[i] << " ";
    return out;
   }
};

int main() {
   ArrayList<int> list;
   for (int i = 1; i <= 5; ++i) list.PushBack(i);
   cout << list;

   return 0;
}
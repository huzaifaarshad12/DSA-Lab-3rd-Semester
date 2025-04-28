#include <iostream>
using namespace std;

template<typename T>
class Vector {
private:
   T* data;
   size_t size;
   size_t capacity;

public:
   Vector() : size(0), capacity(1) { data = new T[capacity]; }

   ~Vector() { delete[] data; }

   void PushBack(T value) {
       if (size == capacity) {
           T* newData = new T[capacity * 2];
           for (size_t i = 0; i < size; ++i) newData[i] = data[i];
           delete[] data;
           data = newData;
           capacity *= 2;
       }
       data[size++] = value;
   }
T operator[](int index) const { return data[index]; }
T& operator[](int index) { return data[index]; }

friend ostream& operator<<(ostream& out, const Vector& vec) {
    for (size_t i = 0; i < vec.size; ++i)
        out << vec.data[i] << " ";
        return out;
   }
};

int main() {
   Vector<int> vec;
   for (int i = 1; i <= 5; ++i) vec.PushBack(i);
   cout << vec;

   return 0;
}
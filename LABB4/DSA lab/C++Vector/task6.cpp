#include <iostream>
using namespace std;

template<typename T>
class AutoGrowingArray {
private:
    T* arr;
    size_t size;
    size_t capacity;

public:
    AutoGrowingArray() : size(0), capacity(1) {
        arr = new T[capacity];
    }

    ~AutoGrowingArray() {
        delete[] arr;
    }

    void PushBack(T value) {
        if (size == capacity) {
            T* newArr = new T[capacity + 1];
            for (size_t i = 0; i < size; i++) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            capacity++;
        }
        arr[size++] = value;
    }
T operator[](int index) const { return arr[index]; }
T& operator[](int index) { return arr[index]; }

friend ostream& operator<<(ostream& out, const AutoGrowingArray& other) {
    for (size_t i = 0; i < other.size; ++i)
        out << other.arr[i] << " ";
        return out;
   }
};

int main() {
   AutoGrowingArray<int> arr;
   for (int i = 1; i <= 5; ++i) arr.PushBack(i);
   cout << arr;

   return 0;
}
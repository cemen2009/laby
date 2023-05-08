#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyArray {
private:
    double* arr;
    int size;
public:
    MyArray(int n) {
        size = n;
        arr = new double[size];
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                arr[i] = i - 1.9;
            } else {
                arr[i] = i;
            }
        }
    }

    ~MyArray() {
        delete[] arr;
    }

    double* getArray() {
        return arr;
    }

    int getSize() {
        return size;
    }
};

void reverseArray(double arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        double temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void reverseMyArray(MyArray& myArray) {
    double* arr = myArray.getArray();
    int size = myArray.getSize();
    reverseArray(arr, size);
    // or simply use std::reverse(arr, arr + size);
}

int main() {
    MyArray myArray(14);
    reverseMyArray(myArray);
    double* arr = myArray.getArray();
    int size = myArray.getSize();
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

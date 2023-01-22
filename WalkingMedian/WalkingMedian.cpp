#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void Sort(int* arr, int size)
{
    int key;
    int j;
    for (size_t i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    double* result = new double[size];
    int count = 1;
    int helper;
    double num1;
    double num2;
    for (size_t k = 0; k < count; k++) {
        cin >> arr[k];
        Sort(arr, count);
        if (count % 2 == 0) {
            helper = count / 2;
            num1 = arr[helper];
            num2 = arr[helper - 1];
            result[k] = (num1 + num2) / 2;
        }
        else {
            helper = count / 2;
            result[k] = arr[helper];
        }

        if (count < size) {
            count++;
        }
    }
    for (size_t i = 0; i < size; i++) {
        cout << result[i] << endl;
    }
    delete[]arr;
    delete[]result;
    return 0;
}

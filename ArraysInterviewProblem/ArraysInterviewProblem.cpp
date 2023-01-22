#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int ignoreNeg(int* arr, int N)
{
    int helper = 0;
    for (size_t i = 0; i < N; i++) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[helper]);
            helper++;
        }
    }
    return helper;
}
int findNum(int* arr, int N)
{
    for (size_t i = 0; i < N; i++) {
        if (abs(arr[i]) - 1 < N and arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for (size_t i = 0; i < N; i++)
        if (arr[i] > 0)
            return i + 1;

    return N + 1;
}
int findFirstPos(int* arr, int N)
{
    int helper = ignoreNeg(arr, N);
    return findNum(arr + helper, N - helper);
}
int main() {
    int N;
    cin >> N;
    int result = 0;
    int* arr = new int[N];
    for (size_t i = 0; i < N; i++) {
        cin >> arr[i];
    }
    result = findFirstPos(arr, N);
    cout << result << endl;

    delete[]arr;
    return 0;
}
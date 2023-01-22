#include<iostream>
#include<unordered_map>

using namespace std;

int maxLen(int* arr, int N) {
    unordered_map<int, int> hM;

    int sum = 0;
    int max_len = 0;
    int ending_index = -1;

    for (int i = 0; i < N; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    for (int i = 0; i < N; i++) {
        sum += arr[i];

        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }
        if (hM.find(sum + N) != hM.end()) {
            if (max_len < i - hM[sum + N]) {
                max_len = i - hM[sum + N];
                ending_index = i;
            }
        }
        else hM[sum + N] = i;
    }

    for (int i = 0; i < N; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;

    return max_len;
}

int main()
{
    int N;
    cin >> N;
    int* arr = new int[N];
    for (size_t i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << maxLen(arr, N);
    delete[] arr;
    return 0;
}
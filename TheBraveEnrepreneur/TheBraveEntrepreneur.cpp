#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    int* prices = new int[N];
    int MaxProfit = 0;
    for (size_t i = 0; i < N; i++) {
        cin >> prices[i];
    }
    int smallest = prices[0];
    int biggest = prices[0];
    for (size_t i = 1; i < N; i++) {
        if (i == N - 1 and prices[i] > biggest) {
            biggest = prices[i];
            MaxProfit += (biggest - smallest);
        }
        if (prices[i] > biggest) {
            biggest = prices[i];
        }
        else  if (prices[i] < biggest) {
            MaxProfit += (biggest - smallest);
            biggest = prices[i];
            smallest = prices[i];
        }
        if (prices[i] < smallest) {
            smallest = prices[i];
        }
    }
    cout << MaxProfit;

    delete[] prices;
    return 0;
}
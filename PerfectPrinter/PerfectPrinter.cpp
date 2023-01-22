#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long int getRes(long long int lowest, long long int highest, long long int* helper, int printers, long long int papers) {
    long long int res;
    while (lowest <= highest) {
        long long int mid = (lowest + highest) / 2;
        long long int done = 0;
        for (int i = 0; i < printers; i++) {
            done += mid / helper[i];
            if (done >= papers)
                break;
        }
        if (done >= papers) {
            highest = mid - 1;
            res = mid;
        }
        else
            lowest = mid + 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int printers;
    long long int papers;
    long long int Result;
    cin >> papers;
    cin >> printers;

    long long int* helper = new long long[printers];
    for (int i = 0; i < printers; i++) {
        cin >> helper[i];
    }
    long long int lowest = 1;
    long long int highest = 1e18;
    Result = getRes(lowest, highest, helper, printers, papers);
    cout << Result << endl;

    delete[]helper;
    return 0;
}
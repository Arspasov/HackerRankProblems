#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool canBePalindrome(string str) {
    vector<char> storage;
    for (int i = 0; i < str.length(); i++) {
        auto pos = find(storage.begin(), storage.end(), str[i]);
        if (pos != storage.end()) {
            auto posi = find(storage.begin(), storage.end(), str[i]);
            storage.erase(posi);
        }
        else {
            storage.push_back(str[i]);
        }
    }
    if (str.length() % 2 == 0 and storage.empty() or (str.length() % 2 == 1 && storage.size() == 1))
    {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int size1;
    cin >> size1;
    string* strings = new string[size1];
    for (size_t i = 0; i < size1; i++) {
        cin >> strings[i];
    }
    bool helper = true;
    for (size_t i = 0; i < size1; i++) {
        string current = strings[i];
        helper = canBePalindrome(current);
        if (helper == true) {
            cout << "TRUE" << endl;
        }
        else {
            cout << "FALSE" << endl;
        }
    }
    delete[] strings;
    return 0;
}
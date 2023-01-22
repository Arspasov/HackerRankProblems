#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


struct Stack
{
    vector<int> data;
    long int minEl;

    long int min()
    {
        return minEl;
    }
    long int peek() const {
        if (data.size() > 0) {
            return data.back();
        }
        else {
            throw std::underflow_error("Stack is empty");
        }
    }
    void pop()
    {
        if (isEmpty() == true) {
            throw std::out_of_range("Stack is empty! ");
            return;
        }
        int top = data.back();
        data.pop_back();
        if (top == minEl) {
            minEl = INT_MAX;
            for (size_t i = 0; i < data.size(); i++) {
                if (data.at(i) < minEl) {
                    minEl = data.at(i);
                }
            }
        }
    }
    void push(int x)
    {
        if (isEmpty() == true) {
            minEl = x;
            data.push_back(x);
            return;
        }
        if (x < minEl) {
            data.push_back(x);
            minEl = x;
        }

        else
            data.push_back(x);
    }
    bool isEmpty() const {
        return data.size() == 0;
    }
};
int main() {
    int count_of_orders;
    cin >> count_of_orders;
    string* orders = new string[count_of_orders];
    long int number_to_push;
    Stack stack;
    long int temp = 0;
    for (size_t i = 0; i < count_of_orders; i++) {
        cin >> orders[i];
        if (orders[i] == "push") {
            cin >> number_to_push;
            stack.push(number_to_push);
        }
        if (orders[i] == "pop") {
            stack.pop();
        }
        if (orders[i] == "peek") {
            cout << stack.peek();
            cout << endl;
        }
        if (orders[i] == "min") {
            cout << stack.min();
            cout << endl;
        }
    }

    return 0;
}
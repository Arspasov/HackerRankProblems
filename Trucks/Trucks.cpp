#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>

using namespace std;

class Stack {
    vector<int> data;
public:
    void push(int number) {
        data.push_back(number);
    }
    void pop() {
        data.pop_back();
    }
    int peek() const {
        if (data.size() > 0) {
            return data.back();
        }
        else {
            throw std::underflow_error("Stack is empty");
        }
    }
    bool isEmpty() const {
        return data.size() == 0;
    }
    void print()
    {
        if (isEmpty() == true)
            return;
        int helper = peek();
        pop();
        print();
        cout << helper << " ";
        push(helper);
    }
};
Stack toReturn(Stack trucks, int N) {
    bool isPositiveFound = false;
    long int previous;
    long int number_to_add;
    int helper = 0;
    for (size_t i = 0; i < N; i++) {
        cin >> number_to_add;
    LOOP:
        if (trucks.isEmpty()) {
            if (number_to_add < 0) {
                cout << number_to_add << " ";
            }
            else {
                isPositiveFound = true;
                trucks.push(number_to_add);
                previous = number_to_add;
            }
        }
        else if (previous < 0 and number_to_add < 0) {
            if (!isPositiveFound) {
                cout << number_to_add << " ";
                previous = number_to_add;
            }
            else {
                trucks.push(number_to_add);
                previous = number_to_add;
            }
        }
        else if (previous > 0 and number_to_add > 0) {
            isPositiveFound = true;
            trucks.push(number_to_add);
            previous = number_to_add;
        }
        else if (previous < 0 and number_to_add > 0) {
            isPositiveFound = true;
            trucks.push(number_to_add);
            previous = number_to_add;
            // continue;
        }
        else if (previous > 0 and number_to_add < 0) {
            helper = abs(number_to_add);
            if (helper == previous) {
                trucks.pop();
                if (trucks.isEmpty() != true) {
                    previous = trucks.peek();
                }
            }
            else if (helper < previous) {
                continue;
            }
            else if (helper > previous) {
                trucks.pop();
                if (trucks.isEmpty() != true) {
                    previous = trucks.peek();
                    goto LOOP;
                }
                else {
                    previous = number_to_add;
                    trucks.push(number_to_add);
                }
            }
        }
    }
    return trucks;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    Stack trucks;

    trucks = toReturn(trucks, N);
    trucks.print();

    return 0;
}
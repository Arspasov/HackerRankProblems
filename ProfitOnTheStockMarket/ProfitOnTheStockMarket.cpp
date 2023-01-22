#include<string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <list>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* previous = nullptr;

    Node(int data, Node* previous = nullptr) {
        this->data = data;
        this->previous = previous;
    }
};
class Queue {
private:
    Node* front = nullptr;
    Node* back = nullptr;
public:
    Queue() = default;
    void copyQueue(const Queue& rhs) {
        Node* i = rhs.front;
        while (i != nullptr) {
            push(i->data);
            i = i->previous;
        }
    }
    void freeMemory() {
        while (front != nullptr) {
            Node* previous = front->previous;
            delete front;
            front = previous;
        }
    }
    Queue(const Queue& rhs) {
        copyQueue(rhs);
    }
    Queue& operator=(const Queue& rhs) {
        if (this != &rhs) {
            freeMemory();
            copyQueue(rhs);
        }
        return *this;
    }
    ~Queue() {
        freeMemory();
    }
    void push(int number) {
        if (isEmpty()) {
            front = new Node(number);
            back = front;
        }
        else {
            back->previous = new Node(number);
            back = back->previous;
        }
    }
    void pop() {
        if (!isEmpty()) {
            Node* oldFront = front;
            front = front->previous;
            delete oldFront;
        }
        else {
            throw std::underflow_error("Queue is empty");
        }
    }
    int peek() const {
        if (!isEmpty()) {
            return front->data;
        }
        else {
            throw std::underflow_error("Queue is empty");
        }
    }
    bool isEmpty() const {
        return front == nullptr;
    }
};

int minDays(Queue arr, int N, int K) {
    Queue storage;
    storage.push(arr.peek());
    int helper = arr.peek();
    arr.pop();
    int count = 1;
    int days = INT_MAX;

    while (storage.isEmpty() != true) {
        if (helper < K and count < days) {
            if (arr.isEmpty() != true) {
                storage.push(arr.peek());
                count++;
                helper += arr.peek();
                arr.pop();
            }
            else {
                helper = helper - storage.peek();
                count--;
                storage.pop();
            }
        }
        if (helper < K and count >= days) {
            storage.pop();
            if (arr.isEmpty() != true) {
                storage.push(arr.peek());
                count++;
                helper += arr.peek();
                arr.pop();
            }
            else {
                helper = helper - storage.peek();
                count--;
                storage.pop();
            }
        }
        else if (helper >= K) {
            if (count < days) {
                days = count;
                helper = helper - storage.peek();
                count--;
                storage.pop();
            }
            else {
                helper = helper - storage.peek();
                count--;
                storage.pop();
            }
        }
    }
    if (days == INT_MAX) {
        return -1;
    }
    else {
        return days;
    }
}
int main() {
    int N;
    long int K;
    Queue numbers;
    int number_to_add;
    int result;
    cin >> N;
    cin >> K;
    for (size_t i = 0; i < N; i++) {
        cin >> number_to_add;
        numbers.push(number_to_add);
    }
    result = minDays(numbers, N, K);
    cout << result;

    return 0;
}
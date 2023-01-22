#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class List {
public:
    Node* head;
    Node* tail;
public:
    List() {
        head = nullptr;
        tail = nullptr;
    }


    void push_back(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        }
        else {
            tail->next = new Node(number);
            tail = tail->next;
        }
    }

    void print()const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }

    Node* reverse_f(Node* prev, Node* current, int nodes_numb) {
        int elements_left = 0;
        Node* check = current;
        while (check != nullptr) {
            elements_left++;
            check = check->next;
        }
        if (elements_left < nodes_numb)nodes_numb = elements_left;


        bool change_head = false;
        if (current == this->head) change_head = true;
        Node* save;
        Node* zero = current;
        Node* previous = prev;

        for (int i = 0; i < nodes_numb; i++) {
            save = current->next;
            current->next = previous;
            previous = current;
            current = save;
            if (i == nodes_numb - 1) {
                if (change_head == true)this->head = previous;
                else {
                    prev->next = previous;
                }
                zero->next = save;
            }
        }
        return zero;
    }



};


int main() {
    int N;//number []
    int X;//reverse []
    int Y;//interval
    cin >> N;
    cin >> X;
    cin >> Y;
    List my_list;

    for (int i = 0; i < N; i++) {
        int new_n;
        cin >> new_n;
        my_list.push_back(new_n);
    }

    Node* previous = nullptr;
    Node* current = my_list.head;
    while (current != nullptr) {
        previous = my_list.reverse_f(previous, current, X);
        current = previous->next;

        for (int j = 0; j < Y; j++) {
            if (current != nullptr && current->next != nullptr) {
                previous = previous->next;
                current = previous->next;
            }
            else break;
        }


    }


    my_list.print();
    return 0;
}
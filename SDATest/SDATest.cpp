#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int INT_MINI = -2147483647 - 1;
const int INT_MAXI = 2147483647;

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* middle;
    DoublyLinkedListNode* tail;
    int size;

    DoublyLinkedList() {
        this->head = nullptr;
        this->middle = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void insert_node(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);
        DoublyLinkedListNode* leftGuard = new DoublyLinkedListNode(INT_MINI);
        DoublyLinkedListNode* rightGuard = new DoublyLinkedListNode(INT_MAXI);

        if (!this->head) {
            this->head = node;
            this->head->prev = leftGuard;
            this->head->next = rightGuard;
            this->middle = this->head;
        }
        else {
            node->prev = this->tail;
            this->tail->next = node;
            node->next = rightGuard;
        }

        this->tail = node;
        size++;
        if (size % 2 == 0 && size > 3)
        {
            this->middle = this->middle->next;
        }
    }
};

void print_singly_linked_list(DoublyLinkedList* list, string sep) {

    if (list->size == 0)
    {
        return;
    }

    DoublyLinkedListNode* node = list->head;

    while (node->data != INT_MAXI) {
        cout << node->data;

        node = node->next;

        if (node->data != INT_MAXI) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void delete_last(DoublyLinkedList* list)
{
    if (list->head->next->data == INT_MAXI)
    {
        delete list->head;
        list->head = nullptr;
        list->size--;
        return;
    }

    DoublyLinkedListNode* rightGuard = list->tail->next;
    DoublyLinkedListNode* toDelete = list->tail;

    list->tail = list->tail->prev;
    list->tail->next = rightGuard;
    delete toDelete;
    list->size--;
    if (list->size % 2 == 1 && list->size > 2)
    {
        list->middle = list->middle->prev;
    }
}

void milenTransform(DoublyLinkedList* list)
{
    if (list->size == 1)
    {
        return;
    }

    if (list->size % 2 == 0)
    {
        DoublyLinkedListNode* newHead = list->middle->next;
        DoublyLinkedListNode* newMiddle = list->tail;
        DoublyLinkedListNode* newTail = list->middle;

        DoublyLinkedListNode* leftGuard = list->head->prev;
        DoublyLinkedListNode* rightGuard = list->tail->next;

        list->middle->next->prev = leftGuard;
        list->middle->next = rightGuard;

        list->tail->next = list->head;
        list->head->prev = list->tail;

        list->head = newHead;
        list->middle = newMiddle;
        list->tail = newTail;
    }
    else
    {
        DoublyLinkedListNode* newHead = list->middle->next;
        DoublyLinkedListNode* newMiddle = list->tail->prev;
        DoublyLinkedListNode* newTail = list->middle;

        DoublyLinkedListNode* leftGuard = list->head->prev;
        DoublyLinkedListNode* rightGuard = list->tail->next;


        list->middle->next->prev = leftGuard;
        list->middle->next = rightGuard;

        list->tail->next = list->head;
        list->head->prev = list->tail;

        list->head = newHead;
        list->middle = newMiddle;
        list->tail = newTail;
    }
}

int main()
{
    int requests;
    cin >> requests;

    DoublyLinkedList* list = new DoublyLinkedList();
    string word;
    int number;

    for (int i = 0; i < requests; i++)
    {
        cin >> word;
        if (word == "add")
        {
            cin >> number;
            list->insert_node(number);
        }
        if (word == "milen")
        {
            milenTransform(list);
        }
        if (word == "gun")
        {
            delete_last(list);
        }
    }

    cout << list->size << "\n";
    print_singly_linked_list(list, " ");

    return 0;
}
// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = nullptr;
    if (position == 0) {
        if (head->next != nullptr) {
            head = head->next;
        }
        else head = nullptr;
    }
    else {
        for (size_t i = 0; i < position; i++) {
            if (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            else if (i == position) {
                previous->next = nullptr;
            }
        }
        if (current)
            previous->next = current->next;
    }
    return head;
}
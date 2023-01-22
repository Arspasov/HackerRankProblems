// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = nullptr;
    for (size_t i = 0; i < position; i++) {
        if (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        else {
            throw std::out_of_range("Cannot insert in invalid position. ");
        }
    }
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data);
    previous->next = temp;
    temp->next = current;
    return head;
}
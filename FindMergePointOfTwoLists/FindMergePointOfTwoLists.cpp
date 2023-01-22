// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* helper;
    while (head1->next != nullptr) {
        helper = head2;
        while (helper->next != nullptr) {
            if (helper == head1) {
                return helper->data;
            }
            helper = helper->next;
        }
        head1 = head1->next;
    }
    return head1->data;
}
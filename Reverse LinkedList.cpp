// Need SinglyLinkedListNode

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* before = NULL;
    SinglyLinkedListNode* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = before;
        before = curr;
        curr = next;
    }
    return before;
}
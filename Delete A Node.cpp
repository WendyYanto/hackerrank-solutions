
// Need SinglyLinkedListNode

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* before = NULL;
    while(position--) {
        before = curr;
        curr = curr->next;
    }
    before->next = curr->next;
    curr = NULL;
    return head;
}

// Need SinglyLinkedListNode

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* list = NULL;
    SinglyLinkedListNode* newHead = NULL;
    while(head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (list == NULL) {
                list = head1;
                newHead = list;
            } else {
                list->next = head1;
                list = list->next;
            }
            head1 = head1->next;
        } else {
            if (list == NULL) {
                list = head2;
                newHead = list;
            } else {
                list->next = head2;
                list = list->next;
            }
            head2 = head2->next;
        }
    }
    if (head1 != NULL) {
        while(head1 != NULL) {
            list->next = head1;
            head1 = head1->next;
            list = list->next;
        }
    } 
    if (head2 != NULL) {
        while(head2 != NULL) {
            list->next = head2;
            head2 = head2->next;
            list = list->next;
        }
    }
    return newHead;
}
 ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;

        if(!head) return NULL;

        while(temp) {
            temp = temp->next;
            length++;
        }

        k = k%length;
        if(k == 0) return head;

        int n = length-k;
        temp = head;

        for(int i=0; i<n-1; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* temp2 = newHead;
        while(temp2->next != NULL) {
            temp2 = temp2->next;
        }

        temp2->next = head;
        head = newHead;

        return head;

    }
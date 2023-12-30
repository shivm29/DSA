// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

// Think of a better approach


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;

        if(head->next == NULL) return NULL;

        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        cout << size << endl;

        int traverse = size-n;
        if(traverse < 1) {
            head = head->next;
            return head;
        }

        temp = head;
        for(int i=0; i<traverse-1; i++){
            temp = temp->next;    
        }

        temp->next = temp->next->next;

        return head;
    }
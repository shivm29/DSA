#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode* head = NULL;

};

ListNode* reverseLL(ListNode* &head) {
      if(head == NULL || head->next == NULL) return head;
    
       ListNode* temp1 = head;
       ListNode* temp2 = head->next;

       head->next = NULL;

       while(temp2 != NULL) {
           ListNode* temp3 = temp2->next;
           temp2->next = temp1;
           temp1 = temp2;
           temp2 = temp3;
       }

        return temp1;
}

ListNode* reverseList(ListNode* head) {

    if(head == NULL || head->next == NULL) return head;

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while(curr != NULL) {
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }

    return prev;



}
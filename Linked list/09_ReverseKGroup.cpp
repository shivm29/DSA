// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode* head = NULL;

};



ListNode* reverseKGroup(ListNode* head, int k) {
    // checking if any group of k left for reversing or not
    ListNode* temp = head;
    for(int i=0; i<k; i++) {
        if(temp == NULL) return head;
        temp = temp->next;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    for(int i=0; i<k; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = reverseKGroup(curr, k);
    return prev;
}
};
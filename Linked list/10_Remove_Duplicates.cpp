// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode* head = NULL;

};




class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if(head == NULL || head->next == NULL ) return head; 

        while(temp != NULL) {
            if(temp->next != NULL && temp->val == temp->next->val) {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }

        return head;
    }
};
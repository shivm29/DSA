// https://leetcode.com/problems/add-two-numbers/submissions/
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

    ListNode* reverseLL(ListNode* &head) {
        if(!head || head->next == NULL) return head;

        ListNode* current = head;
        ListNode* next = NULL;
        ListNode*prev = NULL;

        while(current!=NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* prevNode = NULL;
        int carry = 0;
        // handle the case if any head is null
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        // handle the case if head->next is not null
        while(head1 != NULL && head2 != NULL){
            int totalSum = head1->val + head2->val + carry;
            int digit = totalSum%10;
            carry = totalSum/10;

            ListNode* newnode = new ListNode(digit);
            newnode->next = prevNode;
            prevNode = newnode;

            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1 != NULL) {
            int totalSum = head1->val + carry;
            int digit = totalSum%10;
            carry = totalSum/10;

            ListNode* newnode = new ListNode(digit);
            newnode->next = prevNode;
            prevNode = newnode;
            head1 = head1->next;
        }

        while(head2 != NULL) {
            int totalSum = head2->val + carry;
            int digit = totalSum%10;
            carry = totalSum/10;

            ListNode* newnode = new ListNode(digit);
            newnode->next = prevNode;
            prevNode = newnode;
            head2 = head2->next;
        }

        if(carry) {
            ListNode* newnode = new ListNode(carry);
            newnode->next = prevNode;
            prevNode = newnode;
        }
        prevNode = reverseLL(prevNode);
        return prevNode;

    }
};
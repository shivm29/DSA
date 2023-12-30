// https://leetcode.com/problems/palindrome-linked-list/
#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode* head = NULL;

};


bool isPalindrome(ListNode* head) {

    if(head->next == NULL) return true;

    // slow and fast pointers
    ListNode* temp1 = head;
    ListNode* temp2 = head;

    // calculating mid
    while(temp2->next != NULL) {
        if(temp2->next->next == NULL) {
            break;
        }
        temp2 = temp2->next->next;
        temp1 = temp1->next;
    }

    ListNode* head2 = temp1->next;
    temp1->next = NULL;

// 1 2 1

    // Reversing IInd  LL
    ListNode* prevNode = NULL;
    ListNode* currNode = head2;
    ListNode* nextNode = NULL;


    if(head2->next == NULL) {
        if(head->val == head2->val) return true;
        else return false;
    }

    nextNode = currNode->next;

    while(currNode != NULL) {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        if(nextNode!= NULL) nextNode = nextNode->next;
    }

    // head of 2nd LL is prev node
    temp1 = head;
    while(prevNode != NULL && temp1 != NULL) {
        if(prevNode->val != temp1->val) {
            return false;
        }

        prevNode = prevNode->next;
        temp1 = temp1->next;
    }

    return true;

}
#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode* head = NULL;

};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 0, len2 = 0;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while(temp1 != NULL && temp2 != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        len1++; len2++;
    }

    while(temp1) {
        temp1 = temp1->next;
        len1++;
    }

    while(temp2) {
        temp2 = temp2->next;
        len2++;
    }

    temp1 = headA;
    temp2 = headB;

    if(len2 > len1) {
        int diff = len2 - len1;
        while(diff) {
            temp2 = temp2->next;
            diff--;
        }
    }else if(len2 < len1) {
        int diff = len1 - len2;
        while(diff) {
            temp1 = temp1->next;
            diff--;
        }
    }

    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
}
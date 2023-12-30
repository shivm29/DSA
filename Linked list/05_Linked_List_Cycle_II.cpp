// https://leetcode.com/problems/linked-list-cycle-ii
//  Amazon ✯   Microsoft ✯  
#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode* head = NULL;

};

// using map [VERY NAIVE APPROACH]
ListNode *detectCycle(ListNode *head) {

    if(!head || head->next == NULL) return NULL;

    map<ListNode* , bool> table;
    ListNode* temp = head;

    while(temp != NULL) {
        if(table.count(temp) > 0) return temp;
        else table[temp] = true;

        temp = temp->next;
    }

    return NULL;
}


// using fast and slow pointer 
ListNode *checkLoop(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }else return NULL;

        if(fast == slow) return fast;
    }

    return NULL;
}

ListNode *detectCycle(ListNode *head) {

    if(!head || head->next == NULL) return NULL;
    // check for loop :
    ListNode *meetingNode = checkLoop(head);
    if(meetingNode == NULL) return NULL;

    ListNode *slow = head;

    while(meetingNode != slow) {
        meetingNode = meetingNode->next;
        slow = slow->next;
    }

    return meetingNode;

    

}
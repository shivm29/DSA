#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode* head = NULL;

};

// Efficient Approach

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != 0) {
        if(fast->next->next == 0) return slow->next;

        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* middleNode(ListNode* head) {
    int len = 0;
    ListNode* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    cout << len << endl;
    temp = head;
    int mid = len/2 + 1;
    while(mid-1){
        temp = temp->next;
        mid--;
    }

    return temp;
}
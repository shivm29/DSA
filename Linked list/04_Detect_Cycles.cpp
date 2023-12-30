#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode* head = NULL;

};

// Approach I
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head || head->next == NULL) return false;

        map<ListNode* , bool> table;

        ListNode *temp = head;
        while(temp != NULL) {
            if(table[temp]) return true;
            table[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};



// Approach II 
   bool hasCycle(ListNode *head) {

        if(!head || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        do{
            if(fast && fast->next != NULL) fast = fast->next->next;
            else return false;
            slow = slow->next;
            if(fast == slow) return true;
        }while(slow != NULL);

        // Another approach : 

        // while(fast != NULL){
        //     fast = fast->next;
        //     if(fast != NULL) {
        //         fast = fast->next;
        //         slow = slow->next;
        //     }

        //     // check for loop
        //     if(fast == slow) {
        //         return true;
        //     }
        // }

        return 0;

    }
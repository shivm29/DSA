#include<iostream>
#include<map>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode* head = NULL;

};

void insertAtHead(ListNode* &head, int d) {

    ListNode * newnode = new ListNode();
    if(head == NULL) {
        head = newnode;
        newnode->data = d;
        newnode->next = NULL;
    }else {
        newnode->data = d;
        newnode->next = head;
        head = newnode;
    }

}


void print(ListNode* &head) {
    ListNode * temp = head;

    if(head == NULL) {
        cout << "nothing to print" << endl;
        return;
    }

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout<<endl;
    
}


ListNode* reverseList(ListNode* &head) {


    ListNode *prev = NULL;
    ListNode *current = head;

    while(current != NULL) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void addOne(ListNode* &head) {

    head = reverseList(head);
    int carry = 1;
    ListNode* temp = head;

    while(temp->next != NULL) {
        int totalSum = carry + temp->data;
        int digit = totalSum%10;
        carry = totalSum/10;

        temp->data = digit;
        temp = temp->next;
        if(carry == 0) break;
    }

    if(carry != 0) {
        int totalSum = temp->data + carry;  
        int digit = totalSum%10;
        carry = totalSum/10;
        temp->data = digit;
   
        if(carry != 0){
            // add new node to the end of list
            ListNode *newnode = new ListNode();
            newnode->data = carry;
            temp->next = newnode;
        }
    }

    head = reverseList(head);
}


int main() {

    ListNode *head = NULL;
    insertAtHead(head, 9);
    insertAtHead(head, 9);
    insertAtHead(head, 9);
    print(head);
    addOne(head);
    print(head);


    return 0;
}
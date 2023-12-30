#include <iostream>
using namespace std;

class node {
    public : 
    int data;
    node* next;
    node* head = NULL;

    node() {
            this->data = 0;
            this->next = NULL;
    }

    node(int data) {
            this->data = data;
            this->next = NULL;
    }

};

int findLength(node* &head) {
  node* temp = head;
  int len = 0;

  while(temp != NULL) {
    len++;
    temp = temp->next;
  }
  return len;
}

void insertAtHead(node* &head, node* &tail, int d) {

    node * newnode = new node();
    if(head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->data = d;
        newnode->next = NULL;
    }else {
        newnode->data = d;
        newnode->next = head;
        head = newnode;
    }

}

void insertAtTail(node* &head, node* &tail, int d){

    node *newnode = new node();

    if(head == NULL){

        newnode->next = NULL;
        newnode->data = d;
        head = newnode;
        tail = newnode;

    }else {

        tail->next = newnode;
        newnode->data = d;
        newnode->next = NULL;
        tail = newnode;

    }

}

void print(node* &head) {
    node * temp = head;

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

void insertAtPosition(node* &head, node *&tail, int pos, int d) {

    if(pos == 1) {
        insertAtHead(head, tail, d);
        return;
    };

    node* temp1 = head;

    for(int i=0; i<pos-2; i++) {

        if(temp1->next == NULL) {
            cout << "Invalid position :(" << endl;
            return;
        }
        temp1 = temp1->next;
    }

    node* temp2 = temp1->next;

    node * newnode = new node();
    newnode->data = d;
    newnode->next = temp2;
    temp1->next = newnode; 
}

    


void deleteAtPosition(node* &head, node* &tail, int pos) {

    node * temp = head;

    if(head == tail) {
        head = tail = NULL;
    }

    int len = findLength(head);

    if(pos == 1) {
        head = head->next;
    }
    else if(pos == len) {
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        temp->next = NULL;
    }
    else {
        for(int i=0; i<pos-2; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }
}


int main() {

    node *head = NULL;
    node *tail = NULL;
    
    insertAtTail(head,tail, 0);
    insertAtHead(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    print(head);
    insertAtPosition(head, tail, 6, 33);
    print(head);
    cout<<"length of list: "<<findLength(head)<<endl;
    deleteAtPosition(head, tail, 1);
    deleteAtPosition(head, tail, 1);
    deleteAtPosition(head, tail, 2);
    deleteAtPosition(head, tail, 1);
    print(head);
    cout<<"length of list: "<<findLength(head)<<endl;


    return 0;
}
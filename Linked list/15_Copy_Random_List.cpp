
#include<iostream>
#include<unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;
        Node*it = head;

        // Creating an attached linkedlist 
        while(it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }
        
        it = head;
        while(it) {
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        it = head;
        Node* clonedHead = it->next;
        while(it) {
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next) {
                clonedNode->next = clonedNode->next->next;
            } 

            it = it->next;
        }

        return clonedHead;


    }
};


// mapping approach
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
}
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {

    if(head == NULL) return NULL;

    unordered_map<Node*, Node*> map;

    Node* temp1 = head;
    Node* newNode = new Node(-1);
    Node* head2 = newNode;
    Node* temp2 = head2;
    map[NULL] = NULL;
    
    while(temp1 != NULL) {
        map[temp1] = temp2;
        temp2->val = temp1->val;
        temp1 = temp1->next;
        if(temp1 != NULL) {
            Node* newnode = new Node(-1);
            temp2->next = newnode; 
            temp2 = temp2->next;
        }else {
            temp2->next = NULL;
        }
    }

    temp2 = head2;
    temp1 = head;

    while(temp2 && temp1) {
        temp2->random = map[temp1->random];
        temp2 = temp2->next;
        temp1 = temp1->next;
    }

    return head2;
}
};
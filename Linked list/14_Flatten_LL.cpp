#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};


Node* merge(Node* head1, Node* head2) {
    
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* curr = head1;
    Node* t1 = head1->bottom;
    Node* t2 = head2;
    
    while(t1 && t2) {
        if(t1->data < t2->data) {
            curr->bottom = t1;
            t1 = t1->bottom;
        }else {
            curr->bottom = t2;
            t2 = t2->bottom;
        }
        
        curr = curr->bottom;
    }
    
    if(t1) {
        curr->bottom = t1;
    }
    
    if(t2) {
        curr->bottom = t2;
    }
    
    return head1;
}

Node* mergeFn(Node* head1, Node* head2) {
    
    if(head1 == NULL) return NULL;
    if(head2 == NULL) return head1;

    Node* head3 = head2->next;
    
    head1 = merge(head1, head2);

    return mergeFn(head1, head3);
}

Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL) return NULL;
   else if(root->next == NULL) return root;
   else {
       root = mergeFn(root, root->next);
   }
   
   return root;
   
}

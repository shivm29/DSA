#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
    	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};


  void merge(Node* head, Node* mid) {
      
      if(!head) return;
      if(!mid) return;
     
      Node* curr;
      Node* t1 = head;
      Node* t2 = mid;
      
      if(mid->data < head->data) {
          curr = t2;
          t2 = t2->next;
      }else {
          curr = t1;
          t1 = t1->next;
      }
      
      Node* ptr = curr;
      while(t1 && t2) {
          if(t1->data < t2->data) {
              curr->next = t1;
              t1 = t1->next;
          }else {
              curr->next = t2;
              t2 = t2->next;
          }
          
          curr = curr->next;
      }
      
      while(t1) {
          curr->next = t2;
      }
      
      while(t2) {
          curr->next = t1;
      }
  }
    
    void mergeSortFn(Node* head) {
        
        if(!head || head->next == NULL) return;
        
        // calculating mid
        Node* slow = head;
        Node* fast = head;
        
          while(fast->next != 0) {
            if(fast->next->next == 0) {
                 break;
            }

            fast = fast->next->next;
            slow = slow->next;
        }
        
        Node* mid = slow->next;
        slow->next = NULL;
        
        // dividing : 
        mergeSortFn(head);
        mergeSortFn(mid);
        
        merge(head, mid);
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        mergeSortFn(head);
        
        return head;
       
    }
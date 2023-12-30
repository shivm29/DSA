#include<iostream>
using namespace std;

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        int skipped = 0, deleted = 0;
        struct Node* temp = head;
        struct Node* store = NULL;

        while(temp != NULL) {
            if(skipped < M-1) {
                temp = temp->next;
                skipped++;
            }
            else if (skipped == M-1) {
                store = temp;
                temp = temp->next;
                while(temp!=NULL && deleted < N){
                    temp = temp->next;
                    deleted++;
                }
                
               if(temp!=NULL) {
                    store->next = temp;
                    skipped = 0;
                    deleted = 0;
                    continue;
               }else {
                   store->next = NULL;
                   break;
               }
            }
        }
                 
    }
};
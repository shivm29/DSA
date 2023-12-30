// Code help's approach

vector<int> nodesBetweenCriticalPoints(ListNode* head) {

    vector<int> ans = {-1, -1};

    ListNode* prev = head;
    if(!prev) return ans;
    ListNode* curr = head->next;
    if(!curr) return ans;
    ListNode* nxt = curr->next;
    if(!nxt) return ans;

    int firstCP = -1, lastCP = -1;
    int minDist = INT_MAX;
    int index = 1;

    while(nxt) {
        bool isCP = ((curr->val > nxt->val && curr->val > prev->val) || (curr->val < nxt->val && curr->val < prev->val) ) ? true : false;

        if(isCP && firstCP == -1) {
            firstCP = index;
            lastCP = index;
        }
        else if(isCP) {
            minDist = min(minDist, index-lastCP);
            lastCP = index;
        }

        index++;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }

    // only one or NO critical point found
    if(lastCP == firstCP) return ans;
    else {
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }

    return ans;

}



// my approach : 

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    
    vector<int> cpt;
    ListNode* curr = head;
    if(!curr || curr->next == NULL || curr->next->next == NULL ) return {-1, -1};

    ListNode* prev = head;
    curr = head->next;
    ListNode* next = curr->next;
    int index = 1;

    while(next != NULL) {
        if((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
            cpt.push_back(index);
        }
        prev = curr;
        curr = next;
        next = next->next;
        index++;
    }

    int shortest = -1, longest = -1;
    for(auto i: cpt) {
        cout << i << " ";
    }
    // longest : 
    if(cpt.size() > 1) {
        longest = cpt[cpt.size()-1] - cpt[0];

        for(int i=0; i<cpt.size()-1; i++) {
            int curr = cpt[i+1] - cpt[i];
            if(shortest == -1) shortest = curr;
            shortest = min(shortest, curr);
        }
    }
    
    return {shortest,longest};
}
// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Codehelp approach 
vector<int> factorialII(int N){
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < ans.size(); j++) {
            int x = ans[j]*i + carry;
            ans[j] = x%10;
            carry = x/10;
        }
        
        while(carry) {
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

// My approach | Time limit exceeded on GFG
vector<int> factorialI(int N){
    vector<int> ans = {1};
    if(N == 0 || N == 1) return ans;
    int c = 0;
    int j = 0;

    for(int i = 2; i <= N; i++) {
        j = 0;
        while(j < ans.size()) {
            int product = i*ans[j] + c;
            ans[j] = product%10;
            c = product/10;
            j++;
            if(c > 0) ans.push_back(0);
        }        
    }
    while(ans[ans.size()-1] == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    vector<int> fact = factorialII(100);
    for(auto i:fact) {
        cout << i;
    }
    cout << endl;

    return 0;
}

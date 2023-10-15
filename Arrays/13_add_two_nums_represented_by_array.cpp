// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string calc_Sum(int *a,int n,int *b,int m){
    int carry = 0;
    string ans;
    int i = n-1, j = m-1;
    
    while(i>= 0 && j >=0) {
        int x = a[i] + b[j] + carry;
        int digit = x%10;
        ans.push_back(digit + '0'); // digit + '0' converts int type of digit into char
        carry = x/10;
        i--; j--;
    }
    
    while(i >= 0) {
        int x = a[i] + carry;
        int digit = x%10;
        ans.push_back(digit + '0');
        carry = x/10;
        i--;
    }
    while(j >= 0) {
        int x = b[j] + carry;
        int digit = x%10;
        ans.push_back(digit + '0');
        carry = x/10;
        j--;
    }
    
    if(carry) ans.push_back(carry + '0');
    
    while(ans[ans.size()-1] == '0') ans.pop_back();
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}
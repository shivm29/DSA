// https://leetcode.com/problems/add-strings/

//  Facebook ✯   Wayfair ✯   Microsoft ✯   Google ✯   Oracle ✯   Bloomberg   Amazon   Apple  
// Easy

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string &num1, string &num2, string &ans, int c, int i1, int i2) {

    if(i1 < 0 && i2 < 0 && c == 0) return ans;

    if(i1 >=0 && i2 >= 0) {
        int d = num1[i1] + num2[i2] + c - '0' - '0';
        ans.push_back(d%10+'0');
        c = d/10;
        i1--; i2--;
    }else if(i1 >= 0) {
        int d = num1[i1] + c - '0';
        ans.push_back(d%10+'0');
        c = d/10;
        i1--;
    }
    else if(i2 >= 0) {
        int d = num2[i2] + c - '0';
        ans.push_back(d%10+'0');
        c = d/10;
        i2--;
    }
    else {
        ans.push_back(c%10+'0');
        c = c/10;
    }


    return add(num1, num2, ans, c, i1, i2);
    
}

string addStrings(string num1, string num2) {
    string ans; 
    ans = add(num1, num2, ans, 0, num1.length()-1, num2.length()-1);
    reverse(ans.begin(), ans.end());
    return ans;
}
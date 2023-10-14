// https://leetcode.com/problems/longest-common-prefix
// SAP   Uber   Apple   Adobe   Quora   Google   Amazon   Facebook   Microsoft   Bloomberg  
// Easy

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    // bruteforce : 
    int min = strs[0].length();
    string ans = "";
    bool flag = true;

    for(int i = 0; i < strs.size(); i++) {
        if(min > strs[i].length()) min = strs[i].length();
    }

    for(int i = 0; i < min; i++) {
        for(int j = 0; j < strs.size()-1; j++) {
            if(strs[j][i] != strs[j+1][i]) {
                flag = false;
                break;
            }
        }

        if(flag) ans += strs[0][i];
        else break;
    }

    return ans;
}

int main() {



    return 0;
}
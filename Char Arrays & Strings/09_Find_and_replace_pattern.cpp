// https://leetcode.com/problems/find-and-replace-pattern/

// Medium
// Apple


#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;


string normalize(string &st) {
    char start = 'a';
    char mapping[300] = {0};

    for(int i = 0; i < st.length(); i++) {
        if(mapping[st[i]] == 0) {
            mapping[st[i]] = start;
            start++;
            st[i] = mapping[st[i]];
        }
        else {
            st[i] = mapping[st[i]];
        }
    }

    return st;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

    // first normalize the pattern : 
    normalize(pattern);

    vector<string> ans;
    for(auto ch : words) {
        string st = ch;
        normalize(st);
        if(st == pattern) {
            ans.push_back(ch);
        }
    }

    return ans;
}
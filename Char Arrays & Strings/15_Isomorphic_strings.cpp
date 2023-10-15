// https://leetcode.com/problems/isomorphic-strings/

// Easy

//  Amazon ✯   LinkedIn ✯   Google 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// From leetcode solutions
bool isIsomorphicII(string s, string t) {

    if(s.length() != t.length()) return false;

    int m1[256] = {0}, m2[256] = {0}, n = s.size();

    for(int i = 0; i < n; i++) {
        if(m1[s[i]] != m2[t[i]]) return false;

        m1[s[i]] = i+1;
        m2[t[i]] = i+1;
    }
    
    return true;
}


// My approach
bool isIsomorphic(string s, string t) {

    if(s.length() != t.length()) return false;

    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    vector<int> pattern1;
    vector<int> pattern2;

    for(int i = 0; i < s.length(); i++) {
        if(map1.count(s[i]) == 0) {
            map1[s[i]] = i;
            pattern1.push_back(map1[s[i]]);
        }else {
            pattern1.push_back(map1[s[i]]);
        }

        if(map2.count(t[i]) == 0) {
            map2[t[i]] = i;
            pattern2.push_back(map2[t[i]]);
        }else {
            pattern2.push_back(map2[t[i]]);
        }
    }

    for(int i = 0; i < pattern1.size(); i++) {
        if(pattern1[i] != pattern2[i]) return false;
    }

    return true;
}
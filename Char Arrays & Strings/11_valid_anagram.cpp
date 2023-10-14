// https://leetcode.com/problems/valid-anagram/
// Easy
//  Apple   Amazon   Affirm   Google   Spotify   Facebook   Bloomberg   Microsoft   Goldman Sachs 

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

// time complexity = O(max(s.length(), t.length()))
// solved by me
bool isAnagram(string s, string t) {
    
    if(s.length() != t.length()) return false;

    unordered_map<char, int> map1, map2;

    for(int i = 0; i < s.length(); i++) {
        if(map1.count(s[i]) == 0) map1[s[i]] = 1;
        else map1[s[i]] += 1;
    }

    for(int i = 0; i < t.length(); i++) {
        if(map2.count(t[i]) == 0) map2[t[i]] = 1;
        else map2[t[i]] += 1;
    }

    for(auto c :map1) {
        if(c.second != map2[c.first]) return false;
    }

    return true;
}

// same approach different way: 
bool isAnagramIa(string s, string t) {
    unordered_map<char, int> count;
    
    // Count the frequency of characters in string s
    for (auto x : s) {
        count[x]++;
    }
    
    // Decrement the frequency of characters in string t
    for (auto x : t) {
        count[x]--;
    }
    
    // Check if any character has non-zero frequency
    for (auto x : count) {
        if (x.second != 0) {
            return false;
        }
    }
    
    return true;
}

// TC - O(N logN)
bool IsAnagramII(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}
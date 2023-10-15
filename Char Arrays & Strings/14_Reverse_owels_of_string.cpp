// https://leetcode.com/problems/reverse-vowels-of-a-string/

// Bloomberg

// Easy

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string reverseVowels(string s) {
    string vowels;
    
    for(auto i : s) {
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'|| i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
            vowels += i;
        }
    }

    reverse(vowels.begin(), vowels.end());
    int j = 0;

        for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            s[i] = vowels[j];
            j++;
        }
    }

    return s;
}
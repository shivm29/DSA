// https://leetcode.com/problems/valid-palindrome

//  Facebook ✯   Amazon ✯   Microsoft ✯   Apple ✯   Adobe ✯   Bloomberg   American Express   Yandex   Wayfair  

#include<iostream>
#include<string>
using namespace std;

bool palindromeCheck(string &st, int end, int start) {
    if(start >= end) return true;

    if(tolower(st[start]) != tolower(st[end])) return false;

    return palindromeCheck(st, end-1, start+1);
}

bool isPalindrome(string s) {
    int index = 0;
    while(index < s.length()) {
        if(!isalnum(s[index])){
            s.erase(index, 1);
            continue;
        }
        index++;
    }

    return palindromeCheck(s, s.length()-1, 0);
}
// https://leetcode.com/problems/reverse-string

// Amazon ✯   Microsoft ✯   Adobe ✯   Facebook ✯   tcs ✯   Apple   Intel 

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void reverse(vector<char> &s, int start, int end) {
    if(start >= end) return;
    swap(s[start], s[end]);
    return reverse(s, start+1, end-1);
}

void reverseString(vector<char>& s) {
    reverse(s, 0, s.size()-1);
}
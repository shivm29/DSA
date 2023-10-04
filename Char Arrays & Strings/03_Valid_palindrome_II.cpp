// https://leetcode.com/problems/valid-palindrome-ii/

// Easy
// Apple Amazon Oracle Facebook Microsoft Bloomberg Walmart_Global_Tech

#include <iostream>
#include <string.h>
using namespace std;

// From leetcode submissions with one doubt
bool validPalindromeII(string s) {
    int lo = 0, hi = s.length()-1;
    int count1 = 0, count2 = 0;

    while(lo <= hi) {
        if(s[lo] == s[hi]){
            lo++;
            hi--;
        }
        else {
            count1++;
            lo++;
        }
    }

    lo = 0;
    hi = s.size()-1;

    while(lo <= hi) {
        if(s[lo] == s[hi]) {
            lo++;
            hi--;
        }
        else {
            count2++;
            hi--;
        }
    }
// doubt ?
    if(count1 == 0 || count2 == 0) {
        return true;
    }

    if(count1 == 1 || count2 == 1) {
        return true;
    }

    return false;

}


bool checkPalindrome(string s, int lo, int hi) {
        while(lo <= hi) {
        if(s[lo] != s[hi]) {
            return false;
        }
        hi--;
        lo++;
    }

    return true;
}
// My approach + Optimized by codehelp
bool validPalindromeI(string s) {
    int lo = 0, hi = s.length()-1;

    while(lo <= hi) {
        if(s[lo] == s[hi]) {
            hi--;
            lo++;
        }
        else {
           bool ans1 = checkPalindrome(s, lo, hi-1);
           bool ans2 = checkPalindrome(s, lo+1, hi);

           return ans1 || ans2;

        }
    
    }
   
    return true;
}


int main() {



    return 0;
}
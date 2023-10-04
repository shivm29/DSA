// https://leetcode.com/problems/palindromic-substrings/

// Medium
// Twitter Expedia Facebook

#include <iostream>
#include<string>
using namespace std;

int expand(string s, int i, int j) {
    int count = 0;
    while(i>=0 && j < s.length() && s[i] == s[j]){
        count++;
        i--;
        j++;
    }

    return count;
}

int countSubstrings(string s) {
    int totalCount = 0;

    for(int center = 0; center < s.length(); center++) {
    // FOR ODD
    int oddKaAns = expand(s, center, center);

    // FOR EVEN
    int evenKaAns = expand(s, center, center+1);

    totalCount += oddKaAns + evenKaAns;
    }

    return totalCount;
}


int main() {


    return 0;
}
// https://leetcode.com/problems/custom-sort-string/

// Medium
// Tiktok | Facebook

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static string str;
    static bool compare(char &ch1, char &ch2){
        return (str.find(ch1) < str.find(ch2));
    }

    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), compare);

        return s;
    }
};

string Solution::str;


int main() {


    return 0;
}
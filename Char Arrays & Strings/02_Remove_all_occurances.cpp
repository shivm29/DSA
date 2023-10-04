// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

// Medium
// Google | Amazon | Microsoft | MakeMyTrip

#include <iostream>
#include <string.h>
using namespace std;

// Best approach by leetcode solutions : 
string removeOccurrences(string s, string part) {
    string ans = s;
    int n = s.size(), m = part.size(), i, j;
    for(i = 0, j = 0; i < n; i++) {
        ans[j] = s[i];
        j++;
        if(j >= m && ans.substr(j-m, m) == part) {
            j -= m;
        }
    }

    return ans.substr(0, j);
    }


// IIIrd Approach by Love babbar
string removeOccurrencesIII(string s, string part) {
   
   while(s.find(part) != string::npos){
    s.erase(s.find(part), part.length());
   }

   return s;

}

// IInd Approach by me supported by a hint : You can maintain a stack of characters and if the last character of the pattern size in the stack match the pattern remove them
string removeOccurrencesII(string s, string part) {
    string ans;
    int index = 0, index2 = 0;

    while(s[index] != '\0') {

        ans.push_back(s[index]);
        index++;

        if(ans.length() >= part.length()) {
            index2 = ans.length()-part.length();
            if(ans.substr(index2, part.length()) == part) {
                ans.erase(index2, part.length());
            }
        }
    }

    return ans;
}

// Ist Approach by me
string removeOccurrencesI(string s, string part) {
    int index = 0;
    int size = part.length();

    while(s[index] != '\0') {
        if(s.substr(index, size) == part) {
            s.erase(index, size);

            if(index-size>=0)index -= (size-1);
            else index = 0;
        }
        else {
            index++;
        }
    }

    return s;
}


int main() {


    return 0;
}
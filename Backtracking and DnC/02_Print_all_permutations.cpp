#include<iostream>
using namespace std;

void printPermutations(string &s, int index) {
    if(index >= s.length()) {
        cout << s << " ";
        return;
    }

    for(int j=index; j<s.length(); j++) {
        swap(s[j], s[index]);
        // baki ka recursion sambhal lega
        printPermutations(s, index+1);
        // backtracking
        swap(s[j], s[index]);

    }
}

int main() {
    string s = "abc";
    printPermutations(s, 0);

    return 0;
}
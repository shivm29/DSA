#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

string reverseOnlyLetters(string s) {
    unordered_map<int, string> map;
    int initialLength = s.length(), erased = 0,i = 0;

    while(i < s.length()) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
            i++;
        }
        else{
            map[i + erased] = s[i];
            s.erase(i, 1);
            erased++; // 1
        }
    }
    
    for(auto ch:map ) {
        cout << ch.first << " " << ch.second << endl;
    }

    reverse(s.begin(), s.end());

    for(int i = 0; i < initialLength; i++) {
        if(map.count(i) != 0) {
            s.insert(i, map[i]);
        }
    }

    return s;
}


int main(){

    cout << reverseOnlyLetters("Test1ng-Leet=code-Q!");
   
    return 0;
}

// 28_]

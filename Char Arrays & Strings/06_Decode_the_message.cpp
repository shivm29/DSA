// https://leetcode.com/problems/decode-the-message

// Easy

#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;

// Babbar's approach by char array
string decodeMessage(string key, string message)
{
    // create mapping
    char start = 'a';
    char mapping[280] = {0};

    for (auto ch : key){

        if (ch != ' ' && mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }

    // use mapping
    string ans;

    for (int i = 0; i < message.length(); i++){

        char ch = message[i];

        if (ch == ' '){
            ans.push_back(' ');
        }
        else{
            char decoded = mapping[ch];
            ans.push_back(decoded);
        }
    }

    return ans;
}

// My approach (by unordered map)
string decodeMessage(string key, string message)
{
    unordered_map<char, char> links;
    int index = 0, charNum = 0;
    string ans;

    for (char ch : key){
        if (ch == ' '){
            continue;
        }

        char mappedChar = char('a' + charNum);

        if (links.count(ch) == 0) {
            links[ch] = mappedChar;
            charNum++;
        }
    }

    for (char ch : message) {
        if (ch == ' ') {
            ans.push_back(' ');
        } else {
            ans.push_back(links[ch]);
        }
    }

    return ans;
}   

int main(){

    string ans = decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv");

    cout << ans;

    return 0;
}
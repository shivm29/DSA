// https://leetcode.com/problems/uncommon-words-from-two-sentences

// Easy 
// Google | Facebook

#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
    string s = s1+" "+s2+" ";
    vector<string> v;
    string word = "";
    
    for(int i = 0; i<s.length()+1; i++){
        if(s[i]==' '){
            v.push_back(word);
            word="";
            continue;
        }
        
        word+=s[i];
    }
    
    vector<string> ans;
    unordered_map<string, bool> map;
    
    for (auto w:v){
        if(map.count(w)==0) map[w]=true;
        else map[w]=false;
    }
    
    for(auto x:map){
        if(x.second )ans.push_back(x.first);
    }
    
    return ans;
}



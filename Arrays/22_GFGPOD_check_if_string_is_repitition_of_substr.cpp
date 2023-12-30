#include<iostream>
#include<unordered_map>
using namespace std;

int kSubstrConcat (int n, string s, int k)
{
    if(n%k != 0) return 0;
    int u = 0, f = 0;
    
    unordered_map<string, int> map;
    
    for(int i=0; i<n;) {
        string temp = "";
        
        for(int j=i; j<i+k; j++) {
            temp += s[j];
        }
        
    //   if a new unique substr is encountered then increase the count of unique substr
        if(map[temp] == 0) {
            u++;
        }
        map[temp]++;
        
    //   if any substr's freq equals 2
        if(map[temp] == 2) {
            f++;
        }
        
    //   if there are more than 2 unique substrings
    //   or if there is more than 2 occurances of 2 diffrent unique substrings return false
    
        if(u == 3 || f == 2) return 0;
        
        i += k;
    }
    
    return 1;
    
}
// Incomplete & Incorrect, Correct it
#include <iostream>
#include <vector>
using namespace std;
  
int hammingDist(string str1, string str2)
{
    int i = 0, count = 0;
    while(str1[i]!='\0')
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}
vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) 
{
    int i = 0, j = 1;
    vector<int> ans;
    vector<string> finalAns;
    
    if(n == 0) return finalAns;
    
    if(n == 1){
        finalAns.push_back(words[0]);
        return finalAns;
    }
    
    ans.push_back(0);
    
    while(j < n && i < n) {
        cout << "words[i]" << words[i] <<" words[j]" << words[j] << endl;
        cout << "g[i]" << groups[i] <<" g[j]" << groups[j] << endl;
        cout <<"hamming : " << hammingDist(words[i], words[j]) << endl;

        if(words[i].length() == words[j].length() && groups[i] != groups[j] && hammingDist(words[i], words[j]) == 1) {
                ans.push_back(j);
                i = j;
                j++;
        }
        else {
            j++;
        }
    }
    
    for(auto i: ans) {
        finalAns.push_back(words[i]);
    }
    
    
    return finalAns;
}


int main() {

    vector<string> v1 = {"baa", "ada"};
    vector<int> v2 = {1,2};
    vector<string> ans = getWordsInLongestSubsequence(2,v1, v2);

    for(auto i: ans) {
        cout << i << endl;
    }

    // cout << hammingDist("baa", "ada");

    return 0;
}
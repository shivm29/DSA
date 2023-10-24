#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// Appproach from Leetcode solutions : 
vector<vector<string>> groupAnagramsI(vector<string> &strs){
    unordered_map <string, vector<string>> map;

    for(auto i:strs) {
        string s = i;
        sort(i.begin(), i.end());
        map[i].push_back(s);
    }

    vector<vector<string>> ans;
    for(auto i:map) {
        ans.push_back(i.second);
    }

    return ans;
}

// My approach : Time limit Exceeded in Letcode :(
vector<vector<string>> groupAnagramsII(vector<string> &strs)
{

    unordered_map<char, int> map1, map2;
    vector<vector<string>> ans;

    if(strs.size() == 0) return ans;
    else if(strs.size() == 1) {
        ans.push_back({strs[0]});
        return ans;
    }

    int index2 = 0;

    for (int i = 0; i < strs[0].size(); i++){
        map1[strs[0][i]]++;
    }

    ans.push_back({strs[0]});
    int ansIndex = 0;
    strs.erase(strs.begin() + 0);

    while (strs.size())  {

        if (index2 >= strs.size()){
            index2 = 0;
            map1.clear();
            for (int i = 0; i < strs[index2].size(); i++){
                map1[strs[index2][i]]++;
            }
            ans.push_back({strs[index2]});
            strs.erase(strs.begin() + index2);
            ansIndex++;
            continue;
        }

        map2.clear();

        for (int i = 0; i < strs[index2].length(); i++){
           map2[strs[index2][i]]++;
        }

        if (map2 == map1){
            ans[ansIndex].push_back(strs[index2]);
            strs.erase(strs.begin() + index2);
        }
        else
        {
            index2++;
        }
    }

    return ans;
}

int main()
{

    vector<string> str = {"a", "a", "ab"};
    vector<vector<string>> v = groupAnagramsI(str);

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
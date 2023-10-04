// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Related Question :  remove-all-adjacent-duplicates-in-string-part-II

// Easy
// Amazon | Facebook

#include <iostream>
#include <string.h>
using namespace std;

// By Love Babbar
string removeDuplicatesIII(string s)
{
    string ans = "";
    int index = 0;

    while (index < s.length())
    {

        // if Ans ka rightmost character and s ka current character is same :
        if (ans.length() > 0 && ans[ans.length() - 1] == s[index])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[index]);
        }

        index++;
    }
}

// Solved by me
string removeDuplicatesII(string s)
{
    string ans;
    int i1 = 0;

    while (s[i1] != '\0')
    {

        if (!ans.empty() && s[i1] == ans.back())
        {
            ans.pop_back();
            i1++;
        }
        else
        {
            if (s[i1] == s[i1 + 1])
                i1 = i1 + 2;
            else
            {
                ans.push_back(s[i1]);
                i1++;
            }
        }
    }

    return ans;
}

// Solved by me
string removeDuplicatesI(string s)
{
    int index = 0;

    while (s[index] != '\0')
    {

        if (s[index] == s[index + 1])
        {
            s.erase(index, 2);
            index = 0;
        }
        else
        {
            index++;
        }
    }

    return s;
}

int main()
{
    string s = "axxaya";
    string ans = removeDuplicatesII(s);

    cout << "Ans : " << ans << endl;

    return 0;
}
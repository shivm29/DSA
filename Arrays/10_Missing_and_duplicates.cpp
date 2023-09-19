#include <iostream>
#include <vector>
using namespace std;

// Think about this "visit and mark" concept when constraints are such that array has elements from 1 to N
// TC : O(N) SC : O(1)
// approach I by codehelp
// cannot count duplicate element in {1,2,2,3,4,5,6,7}
void missingAndRepeating(vector<int> &v)
{
    vector<int> ans;

    for (int i = 0; i < v.size(); i++)
    {
        int nextIndex = abs(v[i]) - 1;
        if (v[nextIndex] > 0)
            v[nextIndex] *= (-1);
    }

    for (int i = 0; i < v.size(); i++)
    {

        if (v[i] > 0)
        {
            ans.push_back(i + 1);
        };
    }
    cout << "missing : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << "\nrepeating : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << v[ans[i] - 1] << " ";
    }
}

int main()
{

    vector<int> v = {1, 3, 5, 3, 4};
    missingAndRepeating(v);

    return 0;
}
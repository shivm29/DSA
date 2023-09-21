#include <iostream>
#include <vector>
using namespace std;

// Think about this "visit and mark" concept when constraints are such that array has elements from 1 to N
// TC : O(N) SC : O(1)
// approach I by gfg
void missingAndRepeating(vector<int> &v)
{
    cout << "Repeated numbers is/are : " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[abs(v[i]) - 1] > 0)
            v[abs(v[i]) - 1] *= -1;
        else
            cout << abs(v[i]) << " ";
    }

    cout << "\nMissing numbers is/are : " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            cout << (i + 1) << " ";
    }
}

int main()
{

    vector<int> v = {7, 3, 4, 5, 5, 6, 5};
    missingAndRepeating(v);

    return 0;
}
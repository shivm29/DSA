#include <iostream>
#include <vector>
using namespace std;

// if difference between an element and its index is 1 so move right else move left
int missingElement(vector<int> &v)
{

    int s = 0, e = v.size() - 1;
    int m = s + (e - s) / 2, ans = -1, diff;

    while (s <= e)
    {

        diff = v[m] - m;
        if (diff == 1)
        {
            s = m + 1;
        }
        else if (diff == 2)
        {
            ans = m;
            e = m - 1;
        }

        m = s + (e - s) / 2;
    }
    if (ans == -1)
        return v.size() + 1;
    return ans + 1;
}

int main()
{

    vector<int> v = {1, 2, 3, 5, 6, 7, 8};
    cout << "Missing number is : " << missingElement(v) << endl;

    return 0;
}
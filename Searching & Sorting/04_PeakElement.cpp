#include <iostream>
#include <vector>
using namespace std;

// if v[m+1] > v[m] -> move right else if v[m+1] < v[m] store the ans and movve left for further possibilities 

int peakElement(vector<int> &v)
{

    int s = 0, e = v.size() - 1;
    int m = s + (e - s) / 2, ans = -1, diff;

    while (s < e)
    {
        if (v[m + 1] > v[m])
        {
            s = m + 1;
        }
        else
        {
            ans = v[m];
            e = m;
        }

        m = s + (e - s) / 2;
    }
    return ans;
}

// 1 2 3 4 5 2 1 0

int main()
{

    vector<int> v = {1, 6, 5, 4, 3, 2, 0};
    cout << "Peak element is : " << peakElement(v) << endl;

    return 0;
}
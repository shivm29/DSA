#include <iostream>
#include <vector>

using namespace std;

int nearlySorted(vector<int> v, int target)
{
    int s = 0, e = v.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (m - 1 > 0 && v[m - 1] == target)
        {
            return m - 1;
        }
        else if (v[m] == target)
        {
            return m;
        }
        else if (v[m + 1] == target)
        {
            return m + 1;
        }

        else if (v[m] > target)
        {
            e = m - 2;
        }
        else
        {
            s = m + 3;
        }
        m = s + (e - s) / 2;
    }

    return -1;
}

int main()
{

    vector<int> nums = {20, 10, 30, 50, 40, 70, 60};
    int ans = nearlySorted(nums, 70);

    cout << "ans : " << ans;

    return 0;
}
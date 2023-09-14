#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int target)
{

    int s = 0, e = v.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (v[m] == target)
        {
            return m;
        }
        else if (v[m] > target)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }

    return -1;
}

int main()
{

    vector<int> v = {1, 2, 3, 444, 555, 900};
    cout << "Found @ : " << binarySearch(v, 1);

    return 0;
}
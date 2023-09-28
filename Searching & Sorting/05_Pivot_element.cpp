// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

// ROTATED ARRAY :  
// pivot element k left aur right mein sorted arrays rehti hai

// approach by me
int pivotElement(vector<int> &v)
{
    int s = 0, e = v.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
            return s;

        if (v[m] > v[m + 1] && v[m] > v[m - 1])
            return m;
        else if (v[m] > v[0])
            s = m + 1;
        else
            e = m - 1;

        m = s + (e - s) / 2;
    }

    return -1;
}
// 12, 16, 144, 1, 2, 3, 4
// approach by codehelp
int pivotElementII(vector<int> &v)
{
    int s = 0, e = v.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
            return s;

        if (m + 1 <= v.size() - 1 && v[m] > v[m + 1])
            return m;
        else if (m - 1 >= 0 && v[m] < v[m - 1])
            return m - 1;
        else if (v[0] > v[m])
            e = m - 1;
        else
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return -1;
}

int binarySearch(vector<int> &v, int s, int e, int target)
{

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

int search(vector<int> &v, int target)
{
    int pivotIndex = pivotElement(v);
    int ans;

    if (target >= v[0] && target <= v[pivotIndex])
    {
        return ans = binarySearch(v, 0, pivotIndex, target);
    }
    else
    {
        return ans = binarySearch(v, pivotIndex + 1, v.size() - 1, target);
    }

    return -1;
}

int main()
{

    vector<int> v = {12, 16, 144, 1, 2, 3, 4};
    cout << "Pivot element is : " << search(v, 4);

    return 0;
}
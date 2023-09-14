#include <iostream>
#include <vector>
using namespace std;

// my approach :
void approachI(vector<int> &v)
{
    int a = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < 0)
        {
            swap(v[i], v[a]);
            a++;
        }
    }
}

// code help approach : 
void approachII (vector<int> &v) {
    int l = 0 , h = v.size()-1;

    
}

int main()
{
    vector<int> v = {-10, 2, -1, -2, 0, 100};
    approachI(v);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}

// -10 2 -1 -2 0 100

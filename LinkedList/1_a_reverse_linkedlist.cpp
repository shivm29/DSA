// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main()
{
    int n = 50;
    cout << "start" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (j < n - 1 - i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}

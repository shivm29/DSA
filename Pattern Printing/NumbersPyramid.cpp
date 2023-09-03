// Number & Stars Half pyramid
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {

        int counter = 0;

        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
            counter = j + 1;
        }

        while (counter > 1)
        {
            counter = counter - 1;
            cout << counter << " ";
        }

        cout << endl;
    }

    return 0;
}
// Number & Stars Half pyramid
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        // handles initial gaps
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "  ";
        }
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

//         1
//       1 2 1
//     1 2 3 2 1
//   1 2 3 4 3 2 1
// 1 2 3 4 5 4 3 2 1
#include <iostream>
#include <string.h>
using namespace std;


int main()
{

    char arr[100];
    cout << "Enter string : " << endl;
    cin.getline(arr, 100);

    int gap = (int)'a' - (int)'A';

    for (int i = 0; i < strlen(arr); i++)
    {

        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            int ascii = (int)arr[i] - gap;
            arr[i] = (char)ascii;
        }
    }

    cout << arr;

    return 0;
}
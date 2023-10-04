#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    char arr[100];
    cout << "Enter string : " << endl;
    cin.getline(arr, 100);

    int i = 0;
    while (arr[i] != '\0')
    {
        if (arr[i] == '@')
            arr[i] = ' ';
        i++;
    }

    cout << arr;

    return 0;
}
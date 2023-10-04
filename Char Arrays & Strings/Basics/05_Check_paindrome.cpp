#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(char arr[])
{
    int i = 0, j = strlen(arr) - 1;
    while (i <= j)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main()
{

    char arr[100];
    cout << "Enter string : " << endl;
    cin.getline(arr, 100);

    cout << checkPalindrome(arr);

    return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    char arr[20];
    cout << "Enter array : " << endl;
    cin.getline(arr, 20);

    int ans = 0, i = 0;

    while (arr[i] != '\0')
    {
        ans += 1;
        i++;
    }

    cout << "using while : " << ans << endl;
    cout << "using stl : " << strlen(arr);

    return 0;
}
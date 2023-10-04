#include <iostream>
#include <string.h>
using namespace std;

void reverse(char arr[], int size) {
    int lo = 0, hi = size - 1;

    while(lo <= hi) {
      swap(arr[lo], arr[hi]);
      lo++;
      hi--;
    }
}

int main()
{

   char arr[100];
   cout << "Enter string : " << endl;
   cin.getline(arr, 20);

   reverse(arr, strlen(arr));
   cout<<arr;

    return 0;
}
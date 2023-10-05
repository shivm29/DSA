#include <iostream>
using namespace std;

int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *ptr = arr;

    cout << arr << endl;
    cout << arr[0] << endl;
    cout << &arr << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    cout << *ptr << endl;

    char ch[50] = "shivam";
    char *cptr = ch;

    cout << ch << endl;
    cout << ch[0] << endl;
    cout << &ch << endl;
    cout << &ch[0] << endl;
    cout << cptr << endl;
    cout << *cptr << endl; // because *cptr = *(cptr+0) = cptr[0] = s
    cout << &cptr << endl;

    char c[30] = "statement";
    char *cptr2 = &c[0];

    cout << c << endl; // statement
    cout << &c << endl;// address of c
    cout << *(c + 3) << endl; // t, because *(c+3) = c[3] 
    cout << cptr2 << endl; // statement
    cout << &cptr2 << endl; // address of cptr2
    cout << *(cptr2 + 3) << endl; // t
    cout << cptr2 + 2 << endl; 
    cout << *cptr2 << endl;
    cout << cptr2 + 8 << endl;

    char character = 'a';
    char * charptr = &character;

    cout << charptr; // prints random chars until null char is found

    return 0;
}
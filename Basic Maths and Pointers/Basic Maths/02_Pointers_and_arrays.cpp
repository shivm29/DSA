#include <iostream>
using namespace std;

int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *ptr1 = arr;

    cout << "arr => " << arr << endl;
    cout << "arr[0] => " << arr[0] << endl;
    cout << "&arr => " << &arr << endl;
    cout << "ptr1 => " << ptr1 << endl;
    cout << "&ptr1 => " << &ptr1 << endl;
    cout << "*ptr1 => " << *ptr1 << endl;
    cout << endl;

    // char ch[50] = "shivam";
    // char *ptr = ch;

    // cout << "ch => " << ch << endl;
    // cout << "&ch => " << &ch << endl;
    // cout << "ch[0] => " << ch[0] << endl; // because ch[0] = *ch => *(ch + 0) i.e. ch[0]
    // cout << "ptr => " << ptr << endl;
    // cout << "&ptr => " << &ptr << endl;
    // cout << "*ptr => " << *ptr << endl;

    char ch[40] = "statement";
    char * cptr = &ch[0];

    cout << "ch => " << ch << endl; // statement
    cout << "&ch => " << &ch << endl; // address of ch
    cout << "*(ch + 3) => " << *(ch + 3) << endl; // t
    cout << "cptr => " << cptr << endl; //  statement
    cout << "cptr + 2 => " << cptr + 2 << endl; //  atement
    cout << "cptr + 8 => " << cptr + 8 << endl; //  atement
    cout << "&cptr => " << &cptr << endl; // address of cptr
    cout << "*cptr => " << *cptr << endl; // s (because *(cptr) = *(cptr+0) = ch[0])
    cout << "*(cptr+3) => " << *(cptr + 3) << endl; // t
    cout << "*(cptr+3) => " << *(cptr + 3) << endl; // t
    cout << endl;

    char abc = 'a';
    char *abcptr = &abc;

    cout << abcptr;

    return 0;
}
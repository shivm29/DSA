#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    string name;
    cout << "Taking input : " << endl;
    // to read spaces and tabs :
    getline(cin, name);

    cout << "Printing name : " << name << endl;
    cout << "Printing 1st char : " << name[0] << endl;

    // Do strings have null CHAR? - yes
    int index = 0;
    while (name[index] != '\0')
    {
        cout << index << " : " << name[index] << endl;
        index++;
    }

    // printing NULL char :
    int l = name.length();
    cout << "Null char : "
         << "'" << name[l] << "'" << endl;
    cout << "Null char Ascii value : " << (int)name[l] << endl;

    string desc = "eren yeager is GOAT";
    desc.erase(12, 3);
    cout << desc << endl; // eren yeager GOAT

    string filler = "is ";
    desc.insert(12, filler); // eren yeager is GOAT

    cout << desc << endl;

    return 0;
}
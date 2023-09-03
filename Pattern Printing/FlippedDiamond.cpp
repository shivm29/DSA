// Flipped Diamond
// Hollow Diamond
// Full Pyramid
#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    // Upper half
    for (int i = 0; i < n; i++)
    {
        // Inverted half pyramid of stars
        for(int j = 0; j < n-i; j++) {
            cout << "* ";
        }

        // full pyramid of spaces
        for(int j = 0; j < 2*i + 1; j++) {
            cout << "  ";
        }

        // half pyramid of stars
        for(int j = 0; j < n-i; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++) {
            cout << "* " ;
        }

        for(int j = 0; j < 2*(n-i)-1; j++ ){
            cout << "  ";
        }

         for(int j = 0; j < i + 1; j++) {
            cout << "* " ;
        }

        cout << endl;
    }

    return 0;
}
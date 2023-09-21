#include <iostream>
using namespace std;

int getQuotient(int divident, int divisor)
{
    int s = 0, e = divident;
    int m = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (divisor * m == divident)
        {
            return m;
        }
        else if (divisor * m < divident)
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }

        m = s + (e - s) / 2;
    }
}

int main()
{

    int divident = 29, divisor = -7;

    int ans = getQuotient(abs(divident), abs(divisor));

    if((divident > 0 && divisor < 0) || (divident < 0 && divisor > 0)) {
        ans = 0-ans;
    }

    return 0;
}
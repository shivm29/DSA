#include <iostream>
#include <vector>
using namespace std;

// HW : Exact value upto 3 decimal places
// hint  : for loop for decimal sol

int mySqrt(int x)
{
    int s = 0, e = x, ans = -1;
    long long mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

// solved by me [no reference]
float getDecimal(int x)
{
    float ans = mySqrt(x);
    float decimal = 1;
    float newAns = ans; // 8

    for (int i = 0; i < 4; i++)
    {
        decimal /= 10; // 0.1 - 0.01
        ans = newAns;  // 8 - 8.2
        for (int j = 1; j <= 9; j++)
        {
            decimal *= j; // 0.1 - 0.2 - 0.3 - 0.01

            if ((decimal + ans) * (decimal + ans) == x)
            {
                newAns = ans + decimal;
                return newAns;
            }
            else if ((decimal + ans) * (decimal + ans) < x)
            {
                newAns = ans + decimal; // 8.1 - 8.2 - 8.21
                decimal /= j;           // decimal = 0.1 - 0.1 - 0.01
            }
            else
            {
                decimal /= j; // 0.1
                break;
            }
        }
    }

    return newAns;
}

int main()
{
    cout << getDecimal(82);

    return 0;
}
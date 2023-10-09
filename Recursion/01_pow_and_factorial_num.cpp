#include<iostream>
using namespace std;

int solve(int n, int num) {
    // base case
    if(n == 0) return 1;

    // recursive call
    return num*solve(n-1, num);
}

int factorial(int n) {
    // base case :
    if(n == 1 || n == 0) return 1;

    // processing
    int recursionKaAns = factorial(n-1);
    int finalAns = n*recursionKaAns;
    // recursive call
    return finalAns;
}

int main() {

    int n = 10, num = 4;
    cout<< "Power of : " << num << " is "<<solve(n, num)<<endl;
    cout<< "Factorial of : " << n << " is "<<factorial(n)<<endl;

    return 0;
}
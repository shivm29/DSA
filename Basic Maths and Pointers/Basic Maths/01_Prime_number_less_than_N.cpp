// https://leetcode.com/problems/count-primes/

// Medium
// SAP | Apple | Adobe | Amazon | Tiktok | Microsoft | Capital One

#include <iostream>
#include<algorithm>
#include <string.h>
#include<math.h>
#include<vector>
using namespace std;

// sieve of eratosthenes
// Time complexity = O(Nlog(logN))
int countPrimes(int n) {

    if(n == 0 || n == 1) return 0;

    int ans = 0;
    vector<bool> prime(n, true);
    prime[0] == prime[1] == false;

    for(int i = 2; i <n; i++) {
        if(prime[i]) {
            ans++;
            int multiple= 2;
            while(i*multiple < n) {
                prime[i*multiple] = false;
                multiple++;
            }
        }
    }

    return ans;
}
// ------------------------------------------------------------bool isPrime(int &n) {

bool isPrime(int n) {
        if(n <= 1) return false;

    for(int  i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) return false;
    }

    return true;
}



// 20/66 testcases passed
// Approach I | Time complexity = O(N^1.5) 
int countPrimes(int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(isPrime(i)) ans++;
    }

    return ans;
}
// -----------------------------------------------------------------

int main() {

    return 0;
}
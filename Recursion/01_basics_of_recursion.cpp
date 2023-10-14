#include <iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int solve(int n, int num)
{
    // base case
    if (n == 0)
        return 1;

    // recursive call
    return num * solve(n - 1, num);
}

int factorial(int n)
{
    // base case :
    if (n == 1 || n == 0)
        return 1;

    // processing
    int recursionKaAns = factorial(n - 1);
    int finalAns = n * recursionKaAns;
    // recursive call
    return finalAns;
}

void printCounting(int n)
{
    // base case
    if (n == 0)
        return;
    // processing
    cout << n << " ";
    // recursive call
    printCounting(n - 1);
}

int fibonacci(int n)
{

    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
        return 1;

    // processing :
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void traverseArray(int arr[], int n, int index) {
    // base case
    if(index >= n) return;

    cout << arr[index] << " ";
    traverseArray(arr, n, index+1);

}

int SearchInArray(int arr[], int n, int index, int target) {
    if(index >= n) return -1;
    if(arr[index] == target) return index;

    return SearchInArray(arr, n, index+1, target);
} 

void minNumberInArray(int arr[], int n, int index, int &m) {
    // base case : 
    if(index >= n) return;

    m = min(m, arr[index]);
    // recursive call :
    minNumberInArray(arr, n, index+1, m);
}

void insertEven(int arr[], int n, int index, vector<int> &v) {
    //base case:
    if(index >= n) return;

    if(arr[index] % 2 == 0) v.push_back(arr[index]);
    insertEven(arr, n, index+1 , v );

}

void printIndexOfAllTargetOccurance(int arr[], int n, int index, int target){

    if(index >= n) return;

    if(arr[index] == target) cout << index << " ";

    printIndexOfAllTargetOccurance(arr, n, index+1, 4);

}

void printDigits(int n) {
    // base case : 
    if(n == 0) return;

    printDigits(n/10);
    cout << n%10 << " ";
}

bool checkSorted(int arr[], int n, int index) {
    // base case
    if(index >= n) return true;

    if(arr[index] > arr[index+1]) return false;
    return checkSorted(arr, n, index+1);


}

int main()
{

    // int n = 10, num = 4;
    // cout << "Power of : " << num << " is " << solve(n, num) << endl;
    // cout << "Factorial of : " << n << " is " << factorial(n) << endl;
    // printCounting(10);
    // cout << "\n"<< fibonacci(7);

    int arr[6] = {100,4,3,4,5,4};
    
    // traverseArray(arr , sizeof(arr)/sizeof(*arr), 0 );

    // int ans = SearchInArray(arr,6,0,6);
    // if(ans == -1) cout << "Not found " << endl;
    // else cout << "Found at : " << ans << endl;

    // int min = INT_MAX;
    // minNumberInArray(arr, 6, 0, min);

    // cout << "minimum number is : " << min << endl;
    // vector<int> evenNumbers;

    // insertEven(arr, 6, 0, evenNumbers);

    // for(auto i:evenNumbers) cout << i << " " ;

    // cout << endl;

    // cout << "indexes of occurance :  " ;
    // printIndexOfAllTargetOccurance(arr, 6, 0, 4);

    // cout << endl;

    // printDigits(2340);

    cout << checkSorted(arr, 6, 0);



    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> add(vector<int> num1, vector<int> num2) {
    int carry = 0;
    vector<int> ans;

    int i = num1.size()-1; 
    int j = num2.size()-1; 


    while(i >= 0 || j >= 0) {
        if( i >= 0 ) {
            if(j >= 0) {
                int lastDigit = num1[i] + num2[j] + carry;
                ans.push_back(lastDigit%10);
                carry = lastDigit/10;
                i--;
                j--;
            }
            else {
                ans.push_back(carry+num1[i]);
                carry = 0;
                i--;
            }
        }
        else {
            ans.push_back(num2[j]+carry+0);
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    vector<int> num1 = {1,2,3,9,5};
    vector<int> num2 = {3,4,9,9,9,9};

    vector<int> ans = add(num1, num2);
    for(auto i: ans) {
        cout << i;
    }
    

    return 0;
}

// 5 -> 1*2*3*4*5
// 120
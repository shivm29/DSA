#include <iostream>
#include <unordered_map>
using namespace std;


int firstRepeated(int arr[], int n) {
    unordered_map<int, int> map;
    
    for(int i=0; i<n; i++) {
        if(map.count(arr[i]) == 0) map[arr[i]] = -(i+1);
        else map[arr[i]] = abs(map[arr[i]]);
    }
    
    int ans = -1;
    
    for(auto i:map) {
        if(i.second > 0 && (ans  == -1 || ans > i.second)) {
            ans = i.second;
        }
    }
    
    return ans;
}

// same approach diff way
int firstRepeatedII(int arr[], int n) {
    unordered_map<int, int> map;

    for(int i= 0; i < n; i++) { 
        map[arr[i]]++;
    }
    
    for(int i=0; i < n; i++) {
        if(map[arr[i]] > 1) return i+1;
    }
    
    return -1;
}

int main(){

    

    return 0;
}
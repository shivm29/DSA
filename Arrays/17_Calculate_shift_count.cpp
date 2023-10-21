#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {

  int N;
  cin >> N;
  int arr[N];
  
  for(int i=0; i<N;i++) {
    cin >> arr[i];
  }

  unordered_map<int, int> map;

  for(int i=0; i<N;i++) {
    map[arr[i]] = i;
  }

  sort(arr, arr + N);

  int ans = 0;
  
  for(int i=0; i<N; i++) {
    ans += abs(map[arr[i]] - i)*arr[i];
  }

  cout << ans << endl;

  return 0;

}
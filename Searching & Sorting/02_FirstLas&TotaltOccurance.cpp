#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> &v, int target) {

  int s = 0, e = v.size() - 1;
  int m = s + (e - s) / 2, ans = -1;

  while (s <= e) {
    if (v[m] == target) {

      ans = m;
      e = m - 1;

    } else if (v[m] > target) {
      e = m - 1;
    } else {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }

  return ans;
}
int LastOccurance(vector<int> &v, int target) {

  int s = 0, e = v.size() - 1;
  int m = s + (e - s) / 2, ans = -1;

  while (s <= e) {
    if (v[m] == target) {

      ans = m;
      s = m + 1;

    } else if (v[m] > target) {
      e = m - 1;
    } else {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }

  return ans;
}

int main() {

  vector<int> v = {1, 2, 3, 444, 444, 444, 444, 555, 555, 555, 555, 555, 900};
  cout << "First Occured  @ : " << firstOccurance(v, 555) << endl;
  cout << "LAst Occured @ : " << LastOccurance(v, 555) << endl;
  cout << "Total Occurance : "
       << LastOccurance(v, 555) - firstOccurance(v, 555) + 1;

  return 0;
}
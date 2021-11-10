#include <iostream>
#include <set>
#include <utility>
#include <map>

using namespace std;
bool compfunc(const pair<int, int>& a, const pair<int, int>& b) {
      if (a.first != b.first) return a.first < b.first;
      else return a.second > b.second;
    }
int main() {
  multiset<pair<int, int>, decltype(&compfunc)> m(&compfunc);
  int run = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      m.insert({i, run});
      run += 1;
    }
  }
  for (auto i : m) {
    cout << i.first << ' ' << i.second << endl;
  }
  return 0;
}
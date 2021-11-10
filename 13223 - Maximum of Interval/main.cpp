#include <iostream>
#include <deque>
#include <utility>
#define endl '\n'

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, l, t;
  cin >> n >> l;
  deque<pair<int, int> > q;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (!q.empty() && q.front().second + l - 1 < i) q.pop_front();
    while (!q.empty()) {
      auto now = q.back();
      if (now.first < t) q.pop_back();
      else break;
    }
    q.push_back({t, i});
    if (i + 1 >= l) cout << q.front().first << ' ';
  }
  cout << endl;

  return 0;
}
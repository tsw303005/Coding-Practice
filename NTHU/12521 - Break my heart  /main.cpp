#include <iostream>
#include <set>

using namespace std;

#define endl '\n'

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> s;
  int n, t, l, r;
  string cmd;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cmd;

    if (cmd == "print" && !s.empty()) {
      int flag = 1;
      for (auto i : s) {
        if (flag) flag = 0;
        else cout << ' ';
        cout << i;
      }
      cout << endl;
    } else if (cmd == "insert") {
      cin >> t;
      s.insert(t);
    } else if (cmd == "min" && !s.empty()) {
      cout << *s.begin() << endl;
    } else if (cmd == "range_erase") {
      cin >> l >> r;
      s.erase(s.lower_bound(l), s.upper_bound(r));
    }
  }

  return 0;
}
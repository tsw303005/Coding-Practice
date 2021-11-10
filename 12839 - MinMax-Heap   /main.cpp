#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  multiset <int> m;
  string cmd;
  int t;
  
  while (cin >> cmd) {
    if (cmd == "PUSH") {
      cin >> t;
      m.insert(t);
    } else if (cmd == "CLEAR") {
      m.clear();
    } else if (cmd == "POPMIN" && !m.empty()) {
      m.erase(m.begin());
    } else if (cmd == "POPMAX" && !m.empty()) {
      m.erase(--m.end());
    } else if (cmd == "MAX" && !m.empty()) {
      cout << *m.rbegin() << endl;
    } else if (cmd == "MAX") {
      cout << "Null\n";
    } else if (cmd == "MIN" && !m.empty()) {
      cout << *m.begin() << endl;
    } else if (cmd == "MIN") {
      cout << "Null\n";
    }
  }

  return 0;
}
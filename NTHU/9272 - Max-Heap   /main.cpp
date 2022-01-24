#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int> q;

  string cmd;
  int t;

  while (cin >> cmd) {
    if (cmd == "PUSH") {
      cin >> t;
      q.push(t);
    } else if (cmd == "TOP" && !q.empty()) {
      cout << q.top() << endl;
    } else if (cmd == "TOP") {
      cout << "Null" << endl;
    } else if (cmd == "POP" && !q.empty()) {
      q.pop();
    }
  }
  return 0;
}
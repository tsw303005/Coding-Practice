#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  string cmd;
  priority_queue <int> q;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "push") {
      cin >> t;
      q.push(t);
    } else if (cmd == "pop") {
      if (!q.empty()) {
        cout << q.top() << "\n";
        q.pop();
      }
    } else {
      if (!q.empty()) {
        cout << q.top() << "\n";
      }
    }
  }

  return 0;
}
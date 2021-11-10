#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<long long int> q;
  string cmd;
  long long int t;

  while (cin >> cmd) {
    if (cmd == "PUSH") {
      cin >> t;
      q.push(-1 * t);
    } else if (cmd == "POP" && !q.empty()) {
      q.pop();
    } else if (cmd == "TOP" && !q.empty()) { 
      cout << -1 * q.top() << endl;
    } else if (cmd == "TOP") cout << "Null\n";
  }

  return 0;
}
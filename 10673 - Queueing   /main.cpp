#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<string> q;
  string name, cmd;

  while (cin >> cmd) {
    if (cmd == "Push") {
      cin >> name;
      q.push(name);
    } else if (cmd == "Pop" && q.size() != 0) {
      q.pop();
    } else if (cmd == "Front" && q.size() != 0) {
      cout << q.front() << endl;
    } else if (cmd == "Front") {
      cout << "empty\n";
    }
  }

  return 0;
}
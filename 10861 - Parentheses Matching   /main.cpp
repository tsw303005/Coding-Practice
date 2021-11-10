#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string cmd;
  cin >> n;
  getline(cin, cmd);
  for (int i = 0; i < n; i++) {
    int flag = 1;
    getline(cin, cmd);
    stack <char> s;
    for (auto c : cmd) {
      if (c == '>' && !s.empty() && s.top() == '<') s.pop();
      else if (c == '<') s.push(c);
      else if (c == ')' && !s.empty() && s.top() == '(') s.pop();
      else if (c == '(') s.push(c);
      else if (c == ']' && !s.empty() && s.top() == '[') s.pop();
      else if (c == '[') s.push(c);
      else if (c == '}' && !s.empty() && s.top() == '{') s.pop();
      else if (c == '{') s.push(c);
      else {
        flag = 0;
        break;
      }
    }
    if (!s.empty()) flag = 0;
    cout << "Case " << i+1 << ':';
    if (flag) cout << " Yes\n";
    else cout << " No\n";
  }
  return 0;
}
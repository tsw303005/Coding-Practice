#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  long long int n, num, tmp;
  long long int ans = 0;
  stack<pair<long long int, long long int> > S;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> num;
    while (!S.empty()) {
      auto now = S.top();
      if (now.first <= num) {
        S.pop();
        tmp = (!S.empty()) ? now.second - S.top().second : now.second;
        ans += ((i + 1 - now.second) * now.first * tmp);
      } else break;
    }
    S.push({num, i + 1});
  }
  while (!S.empty()) {
    auto now = S.top();
    S.pop();
    tmp = (!S.empty()) ? now.second - S.top().second : now.second;
    ans += ((n - now.second + 1) * now.first * tmp);
  }
  cout << ans << endl;
  return 0;
}
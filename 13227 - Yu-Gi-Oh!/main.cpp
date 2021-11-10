#include <iostream>
#include <map>

using namespace std;
#define L long long int

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  L n, t, ans, num;
  num = 0;
  map<L, L> m;
  cin >> n;
  for (L i = 0; i < n; i++) {
    cin >> t;
    if (m.find(t) != m.end()) m[t] += 1;
    else m[t] = 1;
    if (m[t] > num) ans = t, num = m[t];
    else if (m[t] == num && t > ans) ans = t, num = m[t];
    cout << ans << '\n'; 
  }

  return 0;
}
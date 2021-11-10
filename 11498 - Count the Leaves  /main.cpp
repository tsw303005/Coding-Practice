#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, n, root;

  while (cin >> n) {
    if (n == 0) break;

    vector<int> record(1001, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      if (record[a] == -1) record[a] = 1;
      else record[a] += 1;
      if (record[b] == -1) record[b] = 0;
    }
    cin >> root;
    for (int i = 1; i <= 1000; i++) 
      if (record[i] == 0)
        ans += 1;

    cout << ans << endl;
  }

  return 0;
}
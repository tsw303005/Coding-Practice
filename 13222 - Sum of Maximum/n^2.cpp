#include <iostream>
#include <set>

using namespace std;
int N[2000005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  long long int n, num, tmp;
  long long int ans = 0;
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> N[i];

  for (int i = 0; i < n; i++) {
    int M = N[i];
    for (int j = i; j < n; j++) {
      M = max(M, N[j]);
      ans += M;
    }
  }
  cout << ans << endl;
  return 0;
}
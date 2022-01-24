#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define endl '\n'

using namespace std;
int n, m, k;

int towns[500005] = {0};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  vector<vector<int> > road(n+1);
  queue<int> q;
  int a, b, left;

  for (int i = 1; i <= n; i++) towns[i] = INT32_MAX;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    road[a].emplace_back(b);
    road[b].emplace_back(a);
  }

  for (int i = 0; i < k; i++) {
    cin >> a;
    towns[a] = 0;
    q.push(a);
  }

  while(!q.empty()) {
    int tmp = q.front();
    q.pop();
    for (auto j : road[tmp]) {
      if (towns[j] > towns[tmp] + 1) {
        towns[j] = towns[tmp] + 1;
        q.push(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << towns[i] << endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
# define endl '\n'

using namespace std;
using P = pair<int, int>;
int ans[505][505] = {0};
vector<vector<P> > m(505);
unordered_set<int> record;
bool flag = false;

void dfs(int start, int now, int count) {
  ans[start][now] = count;
  for (auto i : m[now]) {
    if (record.find(i.first) == record.end()) {
      record.insert(i.first);
      dfs(start, i.first, count + i.second);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, u, v, x, k, M;
  cin >> n >> q;
  for (int i = 0; i < n-1; i++) {
    cin >> u >> v >> x;
    m[u].push_back({v, x});
    m[v].push_back({u, x});
  }
  for (int i = 0; i < n; i++) {
    record.clear();
    record.insert(i);
    dfs(i, i, 0);
  }
  for (int i = 0; i < q; i++) {
    cin >> k >> M;
    int last, next, tmp;
    tmp = 0;
    cin >> next;
    for (int j = 1; j < k; j++) {
      last = next;
      cin >> next;
      tmp += ans[last][next];
    }
    if (tmp >= M) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
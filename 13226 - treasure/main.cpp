#include <iostream>
#include <queue>
#include <utility>

#define endl '\n'

using namespace std;

int M[205][205] = {0};
const int dir_row[4] = {1, -1, 0, 0};
const int dir_col[4] = {0, 0, 1, -1};
int k_row[205];
int k_col[205];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, n, m;
  int start_row, start_col;
  int ans = 0;
  bool flag = false;
  int run;

  cin >> k >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> M[i][j];
      if (M[i][j] == 2021) {
        k_row[0] = i;
        k_col[0] = j;
        run += 1;
      } else if (M[i][j] != -1 && M[i][j] != 0 && M[i][j] >= 1 && M[i][j] <= k) {
        k_row[M[i][j]] = i;
        k_col[M[i][j]] = j;
      }
    }
  }

  for (run = 1; run <= k; run += 1) {
    queue<pair<int, int> > q;
    bool record[205][205] = {false};
    flag = false;
    q.push({k_row[run-1], k_col[run-1]});
    record[k_row[run-1]][k_col[run-1]] = true;

    while (!q.empty() && !flag) {
      int len = q.size();
      for (int i = 0; i < len; i++) {
        auto tmp = q.front();
        q.pop();
        if (M[tmp.first][tmp.second] == run) {
          flag = true;
          break;
        }
        for (int j = 0; j < 4; j++) {
          if (tmp.first + dir_row[j] <= n && tmp.first + dir_row[j] >= 1 && tmp.second + dir_col[j] >= 1 && tmp.second + dir_col[j] <= m) {
            if (!record[tmp.first + dir_row[j]][tmp.second + dir_col[j]] && M[tmp.first + dir_row[j]][tmp.second + dir_col[j]] != -1) {
              record[tmp.first + dir_row[j]][tmp.second + dir_col[j]] = true;
              q.push({tmp.first + dir_row[j], tmp.second + dir_col[j]});
            }
          }
        }
      }
      if (!flag) ans += 1;
    }
  }

  if (run == k + 1 && flag) cout << ans << endl;
  else cout << "-1" << endl;
  
  return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool record[20][310][410] = {false};
int level[20][2]; // 0 for damage, 1 for healing
using State = vector<int>;
int L, HP, MHP, MDMG;

bool check(State s) {
  if (s[0] > L) return false;
  else if (s[1] <= 0 || s[0] < 0 || s[2] < 0 || s[2] > 400) return false;
  else if (record[s[0]][s[1]][s[2]]) return false;
  record[s[0]][s[1]][s[2]] = true;
  return true;
}

bool check_victory(State s) {
  if (s[2] <= 0) return true;
  else return false;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  int run;
  bool flag = false;
  queue<State> q;

  cin >> L >> HP >> MHP >> MDMG;
  for (int i = 1; i <= L; i++) {
    cin >> level[i][0] >> level[i][1];
  }
  State start = {1, HP, MHP}; // 0 for level, 1 for my HP, 2 for monster HP
  q.push(start);

  while (!q.empty()) {
    run = q.size();
    for (int i = 0; i < run; i++) {
      auto tmp = q.front();
      q.pop();
      if (check_victory(tmp)) {
        cout << ans << endl;
        return 0;
      } else if (!check(tmp)) {
        continue;
      } else {
        q.push({tmp[0]+1, min(tmp[1]-MDMG, HP), tmp[2]});
        q.push({tmp[0], min(tmp[1]-MDMG, HP), tmp[2]-level[tmp[0]][0]});
        q.push({tmp[0], min(tmp[1] + level[tmp[0]][1], HP) - MDMG, tmp[2]});
      }
    }
    ans += 1;
  }
  cout << "-1\n";
  return 0;
}
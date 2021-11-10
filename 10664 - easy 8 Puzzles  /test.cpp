#include <iostream>
#include <unordered_map>
#include <queue>
#include <math.h>
# define endl '\n'

using namespace std;

const string ans = "123456780";
const int dir_row[] = {1, -1, 0, 0};
const int dir_col[] = {0, 0, 1, -1};
const int place_row[] = {3, 1, 1, 1, 2, 2, 2, 3, 3};
const int place_col[] = {3, 1, 2, 3, 1, 2, 3, 1, 2};
const int change_place[] = {3, -3, 1, -1};
unordered_map<string, int> m;

int check(string now) {
  int re = 0;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      int tmp = (i-1)*3 + j-1;
      int t = now[tmp] - '0';
      if (t != 0) re += (abs(place_row[t]-i) + abs(place_col[t]-j));
    }
  }
  return re;
}

bool recur(string now, int row, int col, int step) {
  if (now == ans) return true;
  else if (step <= 0) return false;
  else if (check(now) > step) return false;

  bool flag = false;
  for (int i = 0; i < 4; i++) {
    int r = row + dir_row[i];
    int c = col + dir_col[i];
    if (r < 3 && r >= 0 && c < 3 && c >= 0) {
      int a = 3 * row + col;
      int b = a + change_place[i];
      string next = now;
      next[a] = now[b];
      next[b] = now[a];
      if (m.find(next) == m.end()) m[next] = 0;
      if (m[next] != 0) continue;
      m[next] = 1;
      flag |= recur(next, r, c, step-1);
      m[next] = 0;
    }
  }
  return flag;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, row, col;
  bool flag;
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    string input = "";
    flag = false;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        char c;
        cin >> c;
        input += c;
        if (c == '0') row = i, col = j;
      }
    }
    
    for (int i = 0; i < 15; i++) {
      flag |= recur(input, row, col, i);
      if (flag) {
        cout << "You can solve it within " << i << " steps." << endl;
        break;
      }
    }
    if (!flag) cout << "You'd better skip this game." << endl;
  }
  return 0;
}
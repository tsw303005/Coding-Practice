#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

unordered_map<string, int> m;
string ans = "01020304050607080910111213141500";

bool a_star_algorithm(string now, int step) {
  int row, col;
  int tmp;
  int ans = 0;
  int run = 0;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      tmp = (now[run*2] - '0')*10 + (now[run*2+1] - '0');
      row = tmp / 4 + 1;
      col = (tmp % 4 == 0) ? 4 : tmp % 4;
      if (tmp == 0) row = 4, col = 4;
      if (tmp != 0) ans += abs(row-i) + abs(col-j);
      run += 1;
    }
  }
  if (ans > step) return false;
  else return true;
}

string down(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place + 8;

  char tmp = now[now_place];
  now[now_place] = now[new_place];
  now[new_place] = tmp;

  tmp = now[now_place+1];
  now[now_place+1] = now[new_place+1];
  now[new_place+1] = tmp;

  return now;
}

string up(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place - 8;

  char tmp = now[now_place];
  now[now_place] = now[new_place];
  now[new_place] = tmp;

  tmp = now[now_place+1];
  now[now_place+1] = now[new_place+1];
  now[new_place+1] = tmp;

  return now;
}

string left(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place - 2;

  char tmp = now[now_place];
  now[now_place] = now[new_place];
  now[new_place] = tmp;

  tmp = now[now_place+1];
  now[now_place+1] = now[new_place+1];
  now[new_place+1] = tmp;

  return now;
}

string right(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place + 2;

  char tmp = now[now_place];
  now[now_place] = now[new_place];
  now[new_place] = tmp;

  tmp = now[now_place+1];
  now[now_place+1] = now[new_place+1];
  now[new_place+1] = tmp;

  return now;
}

bool recur(string now, int step, int row, int col) {
  if (now == ans) return true;
  else if (step <= 0) return false;
  
  if (!a_star_algorithm(now, step)) return false;
  bool flag = false;
  if (row + 1 < 4) {
    string next = down(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row+1, col);
      m[next] = 0;
    }
  } if (row - 1 >= 0) {
    string next = up(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row-1, col);
      m[next] = 0;
    }
  } if (col + 1 < 4) {
    string next = right(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row, col+1);
      m[next] = 0;
    }
  } if (col - 1 >= 0) {
    string next = left(now, row, col);
    if (m.find(next) == m.end() || m[next] == 0) {
      m[next] = 1;
      flag |= recur(next, step-1, row, col-1);
      m[next] = 0;
    }
  }
  return flag;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string start = "";
  int t, row, col;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> t;
      if (t == 0) row = i, col = j;
      start += to_string(t/10);
      start += to_string(t%10);
    }
  }
  //cout << start << endl;

  for (int i = 0;; i++) {
    if (recur(start, i, row, col)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
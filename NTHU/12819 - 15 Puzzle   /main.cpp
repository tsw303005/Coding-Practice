#include <iostream>
#include <unordered_map>
#include <deque>
#include <math.h>
#include <utility>

using namespace std;

unordered_map<string, int> start_m, end_m;
unordered_map<string, pair<int, int> > record; 
deque<string> start_q, end_q;
string ans = "01020304050607080910111213141500";
const int dir_row[] = {1, -1, 0, 0};
const int dir_col[] = {0, 0, 1, -1};
const int place_row[] = {4, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4};
const int place_col[] = {4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3};

int a_star_algorithm(string now) {
  int row, col;
  int tmp;
  int ans = 0;
  int run = 0;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      run = (i-1) * 8 + (j - 1) * 2;
      tmp = (now[run]-'0') * 10 + (now[run+1] - '0');
      ans += (abs(place_row[tmp]-i) + abs(place_col[tmp]-j));
    }
  }
  return ans;
} 

string down(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place + 8;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];

  return re;
}

string up(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place - 8;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];
  return re;
}

string left(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place - 2;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];
  return re;
}

string right(string now, int row, int col) {
  int now_place = row * 8 + col * 2;
  int new_place = now_place + 2;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];
  return re;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string start = "";
  string next;
  int t, row, col;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> t;
      if (t == 0) row = i, col = j;
      start += to_string(t/10);
      start += to_string(t%10);
    }
  }

  start_q.push_back(start);
  end_q.push_back(ans);
  start_m[start] = 0;
  end_m[ans] = 0;
  record[start] = make_pair(row, col);
  record[ans] = make_pair(3, 3);

  int run = 0;
  while (!start_q.empty() || !end_q.empty()) {
    deque<string>& used_q = (start_q.size() <= end_q.size() && start_q.size() != 0) ? start_q : end_q;
    unordered_map<string, int>& used_m = (start_q.size() <= end_q.size() && start_q.size() != 0) ? start_m : end_m;
    unordered_map<string, int>& another_m = (start_q.size() <= end_q.size() && start_q.size() != 0) ? end_m : start_m;
    string q = used_q.front();
    used_q.pop_front();
    if (another_m.find(q) != another_m.end()) {
      cout << start_m[q] + end_m[q]<< endl;
      break;
    } else {
      for (int i = 0; i < 4; i++) {
        next = "";
        row = record[q].first;
        col = record[q].second;
        bool flag = false;
        if (i == 0 && record[q].first + dir_row[i] < 4) {
          next = down(q, row, col);
          flag = true;
        } else if (i == 1 && record[q].first + dir_row[i] >= 0) {
          next = up(q, row, col);
          flag = true;
        } else if (i == 2 && record[q].second + dir_col[i] < 4) {
          next = right(q, row, col);
          flag = true;
        } else if (i == 3 && record[q].second + dir_col[i] >= 0) {
          next = left(q, row, col);
          flag = true;
        }
        if (flag && used_m.find(next) == used_m.end() && next != "") {
          if (a_star_algorithm(q) >= a_star_algorithm(next)) {
            used_q.push_back(next);
            used_m[next] = used_m[q] + 1;
            record[next] = make_pair(record[q].first + dir_row[i], record[q].second + dir_col[i]);
          }
        }
      }
    }
  }
  return 0;
}
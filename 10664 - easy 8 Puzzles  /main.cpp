#include <iostream>
#include <unordered_map>
#include <deque>
#include <math.h>
#include <utility>

using namespace std;

unordered_map<string, int> start_m, end_m;
unordered_map<string, pair<int, int> > record; 
deque<string> start_q, end_q;
string ans = "010203040506070800";
const int dir_row[] = {1, -1, 0, 0};
const int dir_col[] = {0, 0, 1, -1};
const int place_row[] = {3, 1, 1, 1, 2, 2, 2, 3, 3};
const int place_col[] = {3, 1, 2, 3, 1, 2, 3, 1, 2};

string down(string now, int row, int col) {
  int now_place = row * 6 + col * 2;
  int new_place = now_place + 6;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];

  return re;
}

string up(string now, int row, int col) {
  int now_place = row * 6 + col * 2;
  int new_place = now_place - 6;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];
  return re;
}

string left(string now, int row, int col) {
  int now_place = row * 6 + col * 2;
  int new_place = now_place - 2;
  string re = now;
  re[now_place] = now[new_place];
  re[now_place+1] = now[new_place+1];
  re[new_place] = now[now_place];
  re[new_place+1] = now[now_place+1];
  return re;
}

string right(string now, int row, int col) {
  int now_place = row * 6 + col * 2;
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
  int t, row, col, n;
  cin >> n;

  for (int _ = 0; _ < n; _++) {
    start = "";
    record.clear();
    start_q.clear();
    end_q.clear();
    start_m.clear();
    end_m.clear();

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
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
    record[ans] = make_pair(2, 2);

    int run = 0;
    while (!start_q.empty() || !end_q.empty()) {
      deque<string>& used_q = (start_q.size() <= end_q.size() && start_q.size() != 0) ? start_q : end_q;
      unordered_map<string, int>& used_m = (start_q.size() <= end_q.size() && start_q.size() != 0) ? start_m : end_m;
      unordered_map<string, int>& another_m = (start_q.size() <= end_q.size() && start_q.size() != 0) ? end_m : start_m;
      string q = used_q.front();
      used_q.pop_front();
      if (another_m.find(q) != another_m.end()) {
        cout << "You can solve it within ";
        cout << start_m[q] + end_m[q]<< " steps.\n";
        break;
      } else if (used_m[q] > 14) {
        cout << "You'd better skip this game.\n";
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
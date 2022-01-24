#include "function.h"
#include <queue>

using namespace std;

list<State> sol;

void Crossing::solve() {
  State start = {this->_items[0], this->_items[1], this->_items[2], 0, 0, 0, 1};
  this->_explored.insert(start);
  sol.push_back(start);
  this->Go(start, 0, 0, 0);
}

set<State> Crossing::extend(State s) {
  set<State> re;
  State tmp = {s[0], s[1], s[2], s[3], s[4], s[5], -1 * s[6]};
  re.insert(tmp);
  for (int i = 0; i < 3; i++) {
    tmp = {s[0], s[1], s[2], s[3], s[4], s[5], -1 * s[6]};
    if (s[6] == 1) {
      tmp[i] -= 1;
      tmp[i+3] += 1;
    } else if (s[6] == -1) {
      tmp[i] += 1;
      tmp[i+3] -= 1;
    }
    re.insert(tmp);
  }
  return re;
}

bool check_same(State s, State t) {
  return (s[0] == t[0] && s[1] == t[1] && s[2] == t[2] && s[3] == t[3] && s[4] == t[4] && s[5] == t[5] && s[6] == t[6]);
}

State Crossing::Go(State s, int wolf, int goat, int cabbage) {
  queue<list<State> > Q;
  list<State> tmp;
  tmp.push_back(s);
  Q.push(tmp);

  while(!Q.empty()) {
    auto q = Q.front();
    Q.pop();
    if (this->valid(q.back())) {
      this->_explored.insert(q.back());
      if (this->found(q.back())) {
        this->_solutions.insert(q);
        continue;
      }
      auto re = this->extend(q.back());
      for (auto i : re) {
        bool flag = false;
        for (auto j : q) {
          if (check_same(j, i)) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          auto k = q;
          k.push_back(i);
          Q.push(k);
        }
      }
    }
  }
  return s;
}

bool Crossing::valid(State s) {
  if ((s[0] > s[1] && s[1] != 0 && s[6] == -1) || (s[3] > s[4] && s[4] != 0 && s[6] == 1)) return false;
  else if ((s[1] > s[2] && s[2] != 0 && s[6] == -1) || (s[4] > s[5] && s[5] != 0 && s[6] == 1)) return false;
  else if (s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0 || s[4] < 0 || s[5] < 0) return false;
  else return true;
}

bool Crossing::found(State s) {
  if (!s[0] && !s[1] && !s[2] && s[6] == -1) return true;
  else return false;
}
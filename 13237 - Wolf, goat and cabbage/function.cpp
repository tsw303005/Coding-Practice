#include "function.h"

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
  if (this->_explored.find(tmp) == this->_explored.end()) re.insert(tmp);
  for (int i = 0; i < 3; i++) {
    tmp = {s[0], s[1], s[2], s[3], s[4], s[5], -1 * s[6]};
    if (s[6] == 1) {
      tmp[i] -= 1;
      tmp[i+3] += 1;
    } else if (s[6] == -1) {
      tmp[i] += 1;
      tmp[i+3] -= 1;
    }
    if (this->_explored.find(tmp) == this->_explored.end()) re.insert(tmp);
  }
  return re;
}

State Crossing::Go(State s, int wolf, int goat, int cabbage) {
  if (!this->valid(s)) return s;
  else if (this->found(s)) {
    this->_solutions.insert(sol);
    return s;
  } else {
    set<State> re = this->extend(s);
    // cout << s[0] << " " << s[1] << " " << s[2] << ' ' << s[3] << " " << s[4] << ' ' << s[5] << endl;
    for (auto i : re) {
      //if (this->_explored.find(i) != this->_explored.end()) continue;
      sol.push_back(i);
      this->_explored.insert(i);
      Go(i, wolf, goat, cabbage);
      sol.pop_back();
      this->_explored.erase(i);
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
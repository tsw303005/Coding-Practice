#include <iostream>
#include <queue>
#include <deque>
#include <unordered_set>
#define end '\n';

using namespace std;
queue<int> A[4];
deque<int> order;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string cmd;
  int t;

  while (cin >> cmd) {
    if (cmd == "ENQUEUE") {
      cin >> t;
      if (t % 5 == 0) A[3].push(t);
      else {
        A[t%3].push(t);
        if (order.size() == 0) order.push_back(t%3);
        else if (order.size() == 1 && order.front() != t%3) order.push_back(t%3);
        else if (order.size() == 2 && order.front() != t%3 && order.back() != t%3) order.push_back(t%3);
      }
    } else if (cmd == "DEQUEUE") {
      bool flag = false;
      if (!A[3].empty()) {
        flag = true;
        cout << A[3].front();
        A[3].pop();
      }
      if (!order.empty()) {
        if (flag) cout << ' ';
        flag = true;
        cout << A[order.front()].front();
        A[order.front()].pop();
        if (A[order.front()].empty()) order.pop_front();
      }
      if (flag) cout << endl;
    }
  }
  return 0;
}
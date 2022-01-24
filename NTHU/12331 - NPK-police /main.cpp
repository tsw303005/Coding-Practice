#include <iostream>
#include <deque>
#include <queue>
#include <utility>
#define endl '\n'

using namespace std;

queue<int> A[4];
deque<pair<int, int> > order;
int check[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string cmd;
  int t;
  bool polic = false;
  for (int i = 0; i < 3; i++) check[i] = -1;

  while (cin >> cmd) {
    if (cmd == "ENQUEUE") {
      cin >> t;
      A[t%3].push(t);
      if (!polic) {
        if (check[t%3] <= -1) {
          check[t%3] = order.size();
          order.push_back({t%3, 1});
        } else {
          order[check[t%3]].second += 1;
        }
      } else {
        check[t%3] = order.size();
        order.push_back({t%3, 1});
      }
    } else if (cmd == "DEQUEUE" && !order.empty()) {
      cout << A[order.front().first].front() << endl;
      A[order.front().first].pop();
      order.front().second -= 1;
      if (order.front().second == 0) {
        order.pop_front();
        for (int i = 0; i < 3; i++) check[i] -= 1;
      }
    } else if (cmd == "POLICEWATCHING") {
      polic = true;
    } else if (cmd == "DONUTSTIME") {
      polic = false;
    }
  }

  return 0;
}
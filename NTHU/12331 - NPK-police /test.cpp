#include <iostream>
#include <deque>
#include <utility>
#define endl '\n'

using namespace std;
using V = deque<int>;

deque<V> order;
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
      if (!polic) {
        if (check[t%3] <= -1) {
          check[t%3] = order.size();
          order.push_back(V);
          order.back().push_back(t);
        } else {
          order[check[t%3]].push_back(t);
        }
      } else {
        check[t%3] = order.size();
        V tmp;
        tmp.push_back(t);
        order.push_back(tmp);
      }
    } else if (cmd == "DEQUEUE" && !order.empty()) {
      cout << order[0].front() << endl;
      order[0].pop_front();
      if (order[0].size() == 0) {
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
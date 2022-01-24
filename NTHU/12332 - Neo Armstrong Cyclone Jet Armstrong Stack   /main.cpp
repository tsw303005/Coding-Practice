#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_set>
#define endl '\n'

using namespace std;

stack<pair<int, int> > order;
priority_queue<pair<int, int> > M;
priority_queue<pair<int, int>, vector<pair <int, int> >, greater<pair <int, int> > > m;
unordered_set<int> record;
long long int run = 0;

void push(int x) {
  order.push({x, run});
  M.push({x, run});
  m.push({x, -1 * run});
  run += 1;
}

void clean() {
  while (!order.empty() && record.count(order.top().second) != 0) order.pop();
  while (!M.empty() && record.count(M.top().second) != 0) M.pop();
  while (!m.empty() && record.count(-1 * m.top().second) != 0) m.pop();
}

void pop() {
  record.insert(order.top().second);
  clean();
}
void top() {
  cout << order.top().first << endl;;
}
void maxElement() {
  
  cout << M.top().first << endl;
}
void popMax() {
  record.insert(M.top().second);
  clean();
}
void minElement() {
  cout << m.top().first << endl;
}
void popMin() {
  record.insert(-1 * m.top().second);
  clean();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t, n, num;
  string cmd;

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    while (!m.empty()) m.pop();
    while (!M.empty()) M.pop();
    while (!order.empty()) order.pop();
    record.clear();
    cout << "Case #" << i + 1 << ':' <<endl;
    for (int j = 0; j < n; j++) {
      cin >> cmd;
      if (cmd == "push") {
        cin >> num;
        push(num);
      } else if (cmd == "top") {
        top();
      } else if (cmd == "maxElement") {
        maxElement();
      } else if (cmd == "popMax") {
        popMax();
      } else if (cmd == "minElement") {
        minElement();
      } else if (cmd == "popMin") {
        popMin();
      } else if (cmd == "pop") {
        pop();
      }
    }
  }

  return 0;
}
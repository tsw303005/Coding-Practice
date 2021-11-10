#include <iostream>
#include <queue>
#include <deque>
#define endl '\n'
using namespace std;

queue<int> A[3];
deque<int> total;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  string cmd;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "ENQUEUE") {
      cin >> t;
      A[t%3].push(t);
      if (total.size() == 0) {
        total.push_back(t % 3);
      } else if (total.size() == 1 && total.front() != t % 3) {
        total.push_back(t % 3);
      } else if (total.size() == 2 && total.front() != t % 3 && total.back() != t % 3) {
        total.push_back(t % 3);
      }
    } else if (cmd == "DEQUEUE" && total.size() != 0) {
      cout << A[total.front()].front() << endl;
      A[total.front()].pop();
      if (A[total.front()].size() == 0) total.pop_front();
    }
  }

  return 0;
}
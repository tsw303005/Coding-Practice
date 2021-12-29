/*
每個 events 有 start day 跟 end day [1, 2] 代表這個 events 可以在 1 ~ 2 這些天數內參加

input: 給定一個 list [[1, 2], [2, 3], [3, 4]]
output 最多可以參加幾個 events: 3
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareInterval(vector<int> i1, vector<int> i2) {
    if (i1[1] != i2[1]) return (i1[1] > i2[1]);
    else return (i1[1] - i1[0] < i2[1] - i2[0]);
}

int find_result(vector<vector<int> > A) {
  int now = -1;
  int ans = 0;

  sort(A.begin(), A.end(), compareInterval);

  for (auto i : A) {
    if (now == -1) {
      ans += 1;
      now = i[1];
    } else if (now > i[0]) {
      ans += 1;
      now = (now > i[1]) ? i[1] : now - 1;
    }
  }

  return ans;
}

int main() {
  cout << "ans: " << find_result(vector<vector<int> >{{99, 100}, {98, 100}, {98, 98}, {98, 99}}) << endl;

  return 0;
}
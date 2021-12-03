#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void print(int a) {
  if (a == -1) cout << "No winner\n";
  else cout << "The winner is: " << a << endl;
}

void call(int n, int m, vector<int> vec) {
  unordered_map <int, int> um;
  int middle = n / 2;

  for (int i = 0; i < n; i++) {
    if (um.find(vec[i]) != um.end()) um[vec[i]]++;
    else um[vec[i]] = 1;
    if (um[vec[i]] > middle) {
      print(vec[i]);
      return ;
    }
  }
  print(-1);
} 

int main() {
  int n, m;
  n = 6;
  m = 5;

  call(n, m, vector<int>{1, 1, 1, 1, 1, 1});
  call(n, m, vector<int>{1, 1, 1, 3, 3, 3});
  call(n, m, vector<int>{1, 2, 3, 4, 4, 4});

  return 0;
}
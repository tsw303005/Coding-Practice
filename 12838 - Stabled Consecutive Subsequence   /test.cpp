#include <iostream>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

deque<int> D_min;
deque<int> D_max;
queue<int> Q_min;
queue<int> Q_max;
int A[10000005];

int getmin();
int getmax();
void en_min(int n);
void en_max(int n);
void de_min();
void de_max();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, j;
  long long int total;
  
  cin >> n >> k;

  total = 0;
  j = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < n; i++) {
    en_min(A[i]);
    en_max(A[i]);
    
    while (getmax() - getmin() > k) {
      
      de_min();
      de_max();
      j++;
    }
    total = total + (i - j);
  }
  total += n;

  cout << total << endl;
  return 0;
}

int getmin() {
  return D_min.front();
}

void en_min(int n) {
  Q_min.push(n);

  while (!D_min.empty() && D_min.back() > n) {
    D_min.pop_back();
  }
  D_min.push_back(n);
}

void de_min() {
  if (D_min.front() == Q_min.front()) {
    D_min.pop_front();
    Q_min.pop();
  } else {
    Q_min.pop();
  }
}

int getmax() {
  return D_max.front();
}

void en_max(int n) {
  Q_max.push(n);

  while (!D_max.empty() && D_max.back() < n) {
    D_max.pop_back();
  }
  D_max.push_back(n);
}

void de_max() {
  if (D_max.front() == Q_max.front()) {
    D_max.pop_front();
    Q_max.pop();
  } else {
    Q_max.pop();
  }
}


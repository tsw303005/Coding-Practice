#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map<long long int, int> startm;
map<long long int, int> endm;
queue<pair<string, int> > qs, qe;

int main() {
  int step;
  unsigned t;
  unsigned long long  s = 1;
  for (int i = 0; i < 4; i++) {
    scanf("%d", &t);
    while (t != 0) {
      int tmp = t % 2;
      s << 1;
      if (tmp) s += 1;
      t >> 1;
      cout << t << endl;
    }
  }
  for (int i = 0; i < 4; i++) {
    int tmp = 0;
    int temp;
    for (int j = 0; j < 4; j++) {
      temp = s % 2;
      tmp *= 2 + temp;
      s >> 1;
    }
    cout << tmp << " \n";
  }

  return 0;
}
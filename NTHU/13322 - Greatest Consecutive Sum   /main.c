#include <stdio.h>
#include <stdlib.h>


int main() {
  int n, t;
  int Max, now;
  scanf("%d", &n);

  now = Max = -10000;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t + now < 0) now = t; // t + now < 0 的話就後面有正數一定更大
    else now += t;
    Max = (now > Max) ? now : Max;
    if (now < 0) now = 0;
  }
  printf("%d\n", Max);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int arr[41] = {0};

int stair(int n) {
  if (arr[n]) return arr[n];
  else if (n == 0) return 1;
  else if (n < 0) return 0;
  return (arr[n] = stair(n-1) + stair(n-2));
}

int main() {
  int t; scanf("%d", &t);
  int n;

  while (t--) {
    scanf("%d", &n);
    printf("%d\n", stair(n));
  }

  return 0;
}
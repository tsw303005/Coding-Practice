#include <stdio.h>
#include <stdlib.h>

void hanoi(int now, int start, int buffer, int end) {
  if (now == 1) {
    printf("%d\n", now);
  } else {
    hanoi(now-1, start, end, buffer);
    printf("%d\n", now);
    hanoi(now-1, buffer, start, end);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  hanoi(n, 1, 2, 3);


  return 0;
}
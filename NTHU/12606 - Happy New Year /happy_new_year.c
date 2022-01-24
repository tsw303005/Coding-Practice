#include <stdio.h>


int main() {

  int n;
  int min, max;

  scanf("%d", &n);

  int start, t;
  scanf("%d", &start);
  min = start;
  max = start;

  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t > max) {
      max = t;
    }
    if (t < min) {
      min = t;
    }
  }

  printf("%d\n", ((max-start)+(start-min))*2);
  return 0;
}
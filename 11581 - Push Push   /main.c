#include <stdio.h>

int main() {
  int a, b;
  scanf("%d", &a);
  b = (a % 10) * 1000 + (a / 1000) * 100 + ((a / 100) % 10) * 10 + (a / 10) % 10;

  printf("%d\n", a + b);
  return 0;
}
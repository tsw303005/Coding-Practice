#include <stdio.h>

int main() {
  float t;
  char a, b;

  scanf("%f %c %c", &t, &a, &b);
  if (a == 'C' && b == 'F') t = 9.0 / 5.0 * t + 32.0;
  else if (a == 'F' && b == 'C') t = (t - 32.0) * 5.0 / 9.0;
  printf("%.2f\n", t);
  return 0;
}
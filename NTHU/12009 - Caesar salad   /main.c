#include <stdio.h>

int main() {
  char s[4];
  int n;
  scanf("%s %d", s, &n);
  n %= 26;
  for (int i = 0; i < 3; i++) {
    s[i] = (s[i] - 'A' + n + 26) % 26 + 'A';
  }
  printf("%s\n", s);

  return 0;
}
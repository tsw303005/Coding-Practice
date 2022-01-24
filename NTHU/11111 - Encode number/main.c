#include <stdio.h>

int main() {
  char c;
  for (int i = 0; i < 3; i++) {
    c = getchar();
    printf("%c", c - '0' + 64);
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char operation[35];
int len, run;
int a, b, c, d;

int calculate() {
  int left, right;
  if (operation[run] == '&') {
    run += 1;
    left = calculate(run);
    right = calculate(run);
    if (left == 1 && right == 1) return 1;
    else return 0;
  } else if (operation[run] == '|') {
    run += 1;
    left = calculate(run);
    right = calculate(run);
    if (left == 1 || right == 1) return 1;
    else return 0;
  } else if (operation[run] == 'A') {
    run += 1;
    return a;
  } else if (operation[run] == 'B') {
    run += 1;
    return b;
  } else if (operation[run] == 'C') {
    run += 1;
    return c;
  } else if (operation[run] == 'D') {
    run += 1;
    return d;
  }
}

int main() {
  int len;

  scanf(" %s", operation);
  len = strlen(operation);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          a = i;
          b = j;
          c = k;
          d = l;
          run = 0;
          printf("%d %d %d %d %d\n", i, j, k, l, calculate());
        }
      }
    }
  }
  return 0;
}
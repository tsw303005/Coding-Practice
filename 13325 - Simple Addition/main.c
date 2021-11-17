#include <stdio.h>
#include <string.h>

int main() {
  char c;
  int ans = 0;
  int num = 0;
  int count = 0;
  while (1) {
    ans = 0;
    num = 0;
    count = 0;
    while ((c = getchar()) != '\n') {
      count += 1;
      if (c <= '9' && c >= '0') {
        num = (num * 10 + (c - '0'));
      } else ans += num, num = 0;
    }
    ans += num;
    if (count == 1 && num == 0) break;
    printf("%d\n", ans);
  }

  return 0;
}
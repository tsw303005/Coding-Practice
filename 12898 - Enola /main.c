#include <stdio.h>

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n != m) {
      printf("NO\n");
      char c;
      while ((c = getchar()) != '\n');
      while ((c = getchar()) != '\n');
      continue;
    }
    int arr[26] = {0};
    char c;
    while ((c = getchar()) != ' ') {
      arr[c- 'a'] += 1;
    }
    while ((c = getchar()) != '\n') {
      arr[c- 'a'] -= 1;
    }
    for (int i = 0; i < 26; i++) {
      if (arr[i] != 0) {
        printf("NO\n");
        break;
      } else if (i == 25) {
        printf("YES\n");
      }
    }
  }

  return 0;
}
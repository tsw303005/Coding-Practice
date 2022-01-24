#include <stdio.h>
#include <string.h>

int main() {
  char str[101];

  while (1) {
    int ans = 0;
    int n;
    char c;

    scanf("%[^\n]s", str);
    while ((c = getchar()) != '\n');

    n = strlen(str);
    if (n == 1 && str[0] == '0') break;
    for (int i = 0; i < n; i++) if (str[i] >= 'a' && str[i] <= 'z') ans += (str[i] - 'a' + 1);

    printf("%d\n", ans);
  }

  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  char str[10];
  char str_c[10];
  int n;
  int max = 0;
  int count;

  scanf("%s", str);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    count = 0;
    scanf("%s", str_c);
    for (int j = 0; j < strlen(str_c); j++) {
      if (strncmp(str, &str_c[j], strlen(str)) == 0) count += 1;
    }
    max = (count > max) ? count : max;
  }
  printf("%d", max);

  return 0;
}
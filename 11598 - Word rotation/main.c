#include <stdio.h>
#include <string.h>

int main() {
  char str[1002];
  int len;
  scanf("%s", str);
  len = strlen(str);

  for (int i = 1; i < len; i++) {
    printf("%s", &str[i]);
    for (int j = 0; j < i; j++) printf("%c", str[j]);
    printf("\n");
  }
  printf("%s\n", str);
  return 0;
}
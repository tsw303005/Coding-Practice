#include <stdio.h>
#include <string.h>

int main() {
  char str[10];
  char input[5];
  int num[27] = {0};
  scanf("%s", str);
  scanf("%s", input);
  for (int i = 0; i < strlen(str); i++) num[str[i]-'a'] = i + 1;
  for (int i = 0; i < strlen(input); i++) {
    if ('a' <= input[i] && input[i] <= 'z') printf("%d", num[input[i] - 'a']);
    else printf("%c", str[input[i]-'0'- 1]);
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int letters[27] = {0};

void init() {
  for (int i = 0; i < 26; i++) {
    letters[i] = i+97;
  }
}

int main() {
  init();

  int n, m;
  char str[200005];

  scanf("%d%d", &n, &m);

  memset(str, 0, 200005);

  scanf("%s", str);

  char a, b;

  for (int i = 0; i < m; i++) {
    scanf(" %c", &a);
    scanf(" %c", &b);
    if (a == b) continue;

    for (int j = 0; j < 26; j++) {
      if (letters[j] == (int)a) {
        letters[j] = (int)b;
      }
      else if (letters[j] == (int)b) {
        letters[j] = (int)a;
      }
    } 
  }
	
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    printf("%c", letters[str[i]-97]);
  }
  printf("\n");

  return 0;
}
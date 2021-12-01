#include <stdio.h>
#include <string.h>

int arr[27] = {0};
int len;

void per(int num, char* tmp) {
  if (num == len && num != 0) {
    printf("%s\n", tmp);
    return;
  }
  for (int i = 0; i < 26; i++) {
    if (arr[i] > 0) {
      arr[i] -= 1;
      tmp[num] = i + 'a';
      per(num+1, tmp);
      arr[i] += 1;
    }
  }
}

int main() {
  char input[11];
  scanf("%s", input);
  len = strlen(input);
  char tmp[len+1];
  memset(tmp, '\0', sizeof(tmp));
  for (int i = 0; i < len; i++) {
    arr[input[i] - 'a'] += 1;
  }
  per(0, tmp);
  return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int n, k;
int ans = 0;
int record[1001][1001];
char str[1001];

int find(int a, int b, int time) {
  if (time < 0) return 0;
  else if (time >= b - a + 1 || ans || a >= b) return ans = 1;
  else if (record[a][b] >= time) return 0;
  record[a][b] = time;
  if (str[a] == str[b]) return ans = find(a + 1, b - 1, time) || find (a + 1, b, time - 1) || find(a, b - 1, time - 1);
  else return ans = find (a + 1, b, time - 1) || find(a, b - 1, time - 1);
}

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", str);
  memset(record, -1, sizeof(record));
  if (find(0, n-1, k)) printf("Yes\n");
  else printf("No\n");
  return 0;
}
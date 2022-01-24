#include <stdio.h>

int mat[1001][1001];
int record[1001];
int max_num, row;


int main() {
  int m, n, k, len, t, a, b;
  max_num = -1;

  scanf("%d %d %d", &m, &n, &k);
  for (int i = 0; i < m; i++) {
    record[i] = i;
    len = 0;
    for (int j = 0; j < n; j++) {
      scanf("%d", &t);
      mat[i][j] = t;
      len += t * t;
    }
    if (len > max_num) max_num = len, row = i;
  }

  for (int i = 0; i < k; i++) {
    scanf("%d %d %d", &t, &a, &b);
    if (t == 0) {
      if (a == row) row = b;
      else if (b == row) row = a;
      int tmp = record[a];
      record[a] = record[b];
      record[b] = tmp;
    } else if (t == 1) {
      len = 0;
      for (int i = 0; i < n; i++) {
        mat[record[a]][i] += mat[record[b]][i];
        len += mat[record[a]][i] * mat[record[a]][i];
      }
      if (len > max_num) max_num = len, row = a;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d", mat[record[row]][i]);
    if (i != n-1) printf(" ");
    else printf("\n");
  }

  return 0;
}
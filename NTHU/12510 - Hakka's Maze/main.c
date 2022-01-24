#include <stdio.h>
#include <string.h>

int M[1005][1005];
int ans;
int T_row[1000000];
int T_col[1000000];
int T_result = 0;
int T_count;
int begin_to_T;
int T_to_end;
int isvisited[1005][1005];
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

void dfs(int row, int col, int n, int m) {
  if (row > n || row < 1 || col > m || col < 1) return;
  if (isvisited[row][col] || M[row][col] == 0) return;
  if (ans) return;
  if (M[row][col] >= 2) begin_to_T = 1;
  if (row == n && col == m) {
    ans = 1;
    return;
  }
  isvisited[row][col] = 1;
  for (int i = 0; i < 4 && !ans; i++) dfs(row+row_dir[i], col+col_dir[i], n, m);
}

void init() {
  memset(M, 0, sizeof(M));
  memset(isvisited, 0, sizeof(isvisited));
  ans = 0;
  begin_to_T = 0;
  T_to_end = 0;
  T_count = 0;
}

int main() {
  int t, n, m;
  char c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < n; i++) {
      while ((c = getchar()) != '\n');
      for (int j = 0; j < m; j++) {
        c = getchar();
        if (c == 'T') M[i+1][j+1] = 2, T_row[T_count] = i+1, T_col[T_count] = j+1, T_count++;
        else if (c == '*') M[i+1][j+1] = 1;     
      }
    }
    dfs(1, 1, n, m);
    if (ans) printf("Yes\n");
    else if (!ans && begin_to_T) {
      for (int i = 0; i < T_count; i++) {
        dfs(T_row[i], T_col[i], n, m);
        if (ans) {
          printf("Yes\n");
          break;
        } else if (i == T_count-1) printf("No\n");
      }
    } else printf("No\n");
  }

  return 0;
}
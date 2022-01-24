#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

long long int color[505][505];
int edge[505][505];
int count[505];
int judge[505][505];

void init(int n) {
  for (int i = 0; i <= n; i++) {
    count[i] = 0;
    for (int j = 0; j <= n; j++) {
      color[i][j] = -1;
      judge[i][j] = 0;
    }
  }
}

void dfs(int u, int v, int blacknum) {
  if (judge[u][v]) return ;
  judge[u][v] = 1;
  color[u][v] = blacknum;
  for (int i = 0; i < count[v]; i++) {
    int mid = edge[v][i];
    if (color[v][mid] != 0) {
      dfs(u, mid, blacknum+color[v][mid]);
    } else {
      dfs(u, mid, blacknum);
    }
  }
}


long long int query(int u, int v) {
  return color[u][v];
}

int main() {
  int n, q, u, v, black, k;
  long long int m;
  long long int record = 0;

  scanf("%d%d", &n, &q);
  init(n);
  for (int i = 0; i < n-1; i++) {
    scanf("%d%d%d", &u, &v, &black);
    edge[u][count[u]] = v;
    edge[v][count[v]] = u;
    color[u][v] = color[v][u] = black;
    count[u] += 1;
    count[v] += 1;
  }

  for (int i = 0; i<n; i++) {
      dfs(i, i, 0);
  }

  for (int i = 0; i < q; i++) {
    record = 0;
    scanf("%d %lld", &k, &m);
    scanf("%d", &v);
    for (int j = 1; j < k; j++) {
      u = v;
      scanf("%d", &v);
      record += query(u, v);
    }
    if (record >= m) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}
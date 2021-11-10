#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  struct _Node* next;
  int label;
}Node;

Node* all_node[5005];
int node_neighbor_num[5005];
int leaf[5005];

void init(int n);

int main() {
  int n, u, v, run, now;
  Node* temp;
  Node* head;
  Node* cur;
  Node* last;

  run = 1;
  scanf("%d", &n);
  init(n);
  for (int i = 0; i < n-1; i++) {
    scanf("%d %d", &u, &v);
    temp = malloc(sizeof(Node));
    node_neighbor_num[u]++;
    node_neighbor_num[v]++;
    temp->label = v;
    temp->next = all_node[u];
    all_node[u] = temp;

    temp = malloc(sizeof(Node));
    temp->label = u;
    temp->next = all_node[v];
    all_node[v] = temp;
  }
  while (run <= n-2) {
    for (int i = 1; i <= n; i++) {
      if (node_neighbor_num[i] == 1) {
        int neighbor = all_node[i]->label;
        printf("%d ", neighbor);
        node_neighbor_num[i]--;
        node_neighbor_num[neighbor]--;
        cur = all_node[neighbor];
        last = cur;
        while (cur->label != i) {
          last = cur;
          cur = cur->next;
        }
        if (last == cur) {
          all_node[neighbor] = cur->next;
          free(cur);
        } else {
          last->next = cur->next;
          free(cur);
        }
        run++;
        break;
      }
    }
  }
  
  printf("\n");
  return 0;
}

void init(int n) {
  for (int i = 1; i <= n; i++) {
    all_node[i] = NULL;
    node_neighbor_num[i] = 0;
  }
}

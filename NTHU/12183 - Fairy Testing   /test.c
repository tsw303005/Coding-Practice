#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  struct _Node* left;
  struct _Node* right;
  struct _Node* parent;
  int type; // -1 = &, -2 = |, number
  int ans;
}Node;

int pos;
Node* leaf[100001];

Node* construct(Node* parent) {
  char c;
  int val;
  Node* makeNode = NULL;
  scanf(" %c", &c);

  makeNode = malloc(sizeof(Node));
  makeNode->left = makeNode->right = NULL;
  makeNode->parent = parent;
  makeNode->ans = 0;

  if (c == '|') {
    makeNode->type = -2;
    makeNode->left = construct(makeNode);
    makeNode->right = construct(makeNode);
  } else if ( c == '&') {
    makeNode->type = -1;
    makeNode->left = construct(makeNode);
    makeNode->right = construct(makeNode);
  } else {
    scanf("%d", &val);
    scanf(" %c", &c);
    makeNode->type = 0;
    leaf[val] = makeNode;
  }

  return makeNode;
}

void update(Node* cur) {
  if (cur) {
    if (cur->type == -1) {
      int result = (cur->left->ans == 1 && cur->right->ans == 1) ? 1 : 0;
      if (result != cur->ans) {
        cur->ans = result;
        update(cur->parent);
      }
    } else {
      int result = (cur->left->ans == 1 || cur->right->ans == 1) ? 1 : 0;
      if (result != cur->ans) {
        cur->ans = result;
        update(cur->parent);
      }
    }
  } else return ;
}

int main() {
  int t, leaf_num, operation, changed_leaf;
  Node* head;

  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d%d", &leaf_num, &operation);
    head = construct(NULL);
    for (int j = 0; j < operation; j++) {
      scanf("%d", &changed_leaf);
      leaf[changed_leaf]->ans = (leaf[changed_leaf]->ans == 1) ? 0 : 1;
      update(leaf[changed_leaf]->parent);
      printf("%d\n", head->ans);
    }
  }

  return 0;
}
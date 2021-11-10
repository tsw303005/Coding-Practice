#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  struct _Node* left;
  struct _Node* right;
  int value;
  int height;
} Node;

int height;
int max_value;

void createTree(Node* cur, int n) {
  if (cur->value < n && cur->right == NULL) {
    cur->right = malloc(sizeof(Node));
    cur->right->left = cur->right->right = NULL;
    cur->right->value = n;
    cur->right->height = cur->height + 1;
    if (cur->height+1 > height) {
      height = cur->height + 1;
    }
  } else if (cur->value < n) {
    createTree(cur->right, n);
  } else if (cur->value > n && cur->left == NULL) {
    cur->left = malloc(sizeof(Node));
    cur->left->left = cur->left->right = NULL;
    cur->left->value = n;
    cur->left->height = cur->height + 1;
    if (cur->height+1 > height) {
      height = cur->height + 1;
    }
  } else if (cur->value > n) {
    createTree(cur->left, n);
  }
}

void printf_inorder(Node* cur) {
  if (cur != NULL) {
    printf_inorder(cur->left);
    printf("%d ", cur->value);
    printf_inorder(cur->right);
  } else {
    return ;
  }
}

int find_level_number(int level, Node* cur) {
  if (!cur) return 0;
  if (level == cur->height) {
    return cur->value;
  } else {
    return find_level_number(level, cur->left) + find_level_number(level, cur->right);
  }
}

int find_level(int level, Node* cur) {
  if (!cur) return 0;
  if (level == cur->height) {
    return 1;
  } else {
    return find_level(level, cur->left) + find_level(level, cur->right);
  }
}

int main() {
  int n, t, operation_num;
  char operation[20];
  Node* head = NULL;

  scanf("%d", &n);
  height = 0;
  max_value = -1;

  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (i == 0) {
      height = 1;
      head = malloc(sizeof(Node));
      head->left = head->right = NULL;
      head->value = t;
      head->height = 1;
    } else {
      createTree(head, t);
    }
  }

  scanf("%d", &operation_num);
  for (int i = 0; i < operation_num; i++) {
    scanf(" %s", operation);
    if (operation[0] == 'A') {
      scanf("%d", &t);
      if (t > height || t <= 0) {
        printf("0\n");
      } else {
        int number = find_level(t, head);
        int toatl_value = find_level_number(t, head);
        printf("%.3f\n", (float)toatl_value / (float)number);
      }
    } else if (operation[0] == 'S') {
      scanf("%d", &t);
      if (t > height || t <= 0) {
        printf("0\n");
      } else {
        printf("%d\n", find_level_number(t, head));
      }
    } else if (operation[0] == 'P') {
      if (head == NULL || height == 0) {
        printf("NULL\n");
      } else {
        printf_inorder(head);
        printf("\n");
      }
    } else {
      printf("%d\n", height);
    }
  }

  return 0;
}
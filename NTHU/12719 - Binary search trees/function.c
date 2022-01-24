#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int run = 0;
int total;

Node* findPlace(int min, int max, int* num) {
  if (num[run] < min || num[run] > max || run >= total) {
    return NULL;
  }

  Node* cur = malloc(sizeof(Node));
  cur->ltree = cur->rtree = NULL;
  cur->key = num[run];
  run += 1;
  cur->ltree = findPlace(min, cur->key, num);
  cur->rtree = findPlace(cur->key, max, num);
  return cur;
}

Node *buildBST(int n, int *preOrder) {
  if (n == 0) {
    return NULL;
  }
  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->ltree = head->rtree = NULL;
  head->key = preOrder[0];

  run = 0;
  total = n;
  head = findPlace(INT_MIN, INT_MAX, preOrder);

  return head;
}

void printInOrder(Node *ptr) {
  if (ptr) {
    if (ptr->ltree) {
      printInOrder(ptr->ltree);
    }
    printf("%d ", ptr->key);
    if (ptr->rtree) {
      printInOrder(ptr->rtree);
    }
  }
}

void printPostOrder(Node *ptr) {
  if (ptr) {
    if (ptr->ltree) {
      printPostOrder(ptr->ltree);
    } if (ptr->rtree) {
      printPostOrder(ptr->rtree);
    }
    printf("%d ", ptr->key);
  }
}

void freeTree(Node *ptr) {
  if (!ptr) {
    return ;
  } else {
    if (ptr->ltree) {
      freeTree(ptr->ltree);
    } if (ptr->rtree) {
      freeTree(ptr->rtree);
    }
    free(ptr);
    return ;
  }
}
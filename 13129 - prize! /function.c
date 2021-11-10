#include "function.h"
#include <stdlib.h>
#include <stdio.h>

int total = 0;

void count_clockwise(int n);
void count_counter_clockwise(int n);
Node* left;
Node* right;

Node* createList(int n){
  Node* cur;
  Node* headRe = NULL;
  cur = headRe;
  total = n;
  left = NULL;
  right = NULL;
  
  for (int i = 1; i <= n; i++) {
    if (headRe == NULL) {
      headRe = malloc(sizeof(Node));
      headRe->number = i;
      headRe->next = headRe->prev = NULL;
      cur = headRe;
    } else {
      cur->next = malloc(sizeof(Node));
      cur->next->next = NULL;
      cur->next->prev = cur;
      cur->next->number = i;
      cur = cur->next;
    }
  }

  headRe->prev = cur;
  cur->next = headRe;
  return headRe;
}

void solveJosephus(int n, int m) {
  int lucky_number;

  for (int i = 0; i < m; i++) {
    scanf("%d", &lucky_number);
    
    if (lucky_number % 2 == 1) {
      count_clockwise(lucky_number);
    } else {
      count_counter_clockwise(lucky_number);
    }
  }
}

void count_clockwise(int n) {
  Node* destroy;
  Node* cur;

  if (right == NULL) {
    cur = head;
  } else {
    cur = right;
  }

  if (cur->next == cur) {
    printf("%d\n", cur->number);
    free(cur);
    cur = NULL;
    head = NULL;
    left = right = NULL;
    total = 0;
    return ;
  }

  if (n > total) {
    if (n % total == 0) {
      n = total-1;
    } else {
      n = n % total - 1;
    } 
  } else {
    n -= 1;
  }

  for (int i = 0; i < n; i++) {
    cur = cur->next;
  }
  
  destroy = cur;
  left = cur->prev;
  right = cur->next;
  left->next = right;
  right->prev = left;
  total--;
  printf("%d\n", destroy->number);
  free(destroy);
}

void count_counter_clockwise(int n) {
  Node* destroy;
  Node* cur;

  if (left == NULL) {
    cur = head;
  } else {
    cur = left;
  }

  if (cur->next == cur) {
    printf("%d\n", cur->number);
    free(cur);
    cur = NULL;
    head = NULL;
    left = right = NULL;
    total = 0;
    return ;
  }
  
  if (n > total) {
    if (n % total == 0) {
      n = total-1;
    } else {
      n = n % total - 1;
    } 
  } else {
    n -= 1;
  }
  
  for (int i = 0; i < n; i++) {
    cur = cur->prev;
  }

  left = cur->prev;
  right = cur->next;
  left->next = right;
  right->prev = left;
  destroy = cur;
  total--;
  printf("%d\n", destroy->number);
  free(destroy);
}
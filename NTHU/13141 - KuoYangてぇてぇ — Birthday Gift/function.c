#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

Node* mid = NULL;
Node* cur = NULL;
int node_num = 0;
int op_now = 0;
int flag = 0;

void push(int x) {
  if (head == NULL) {
    node_num = 0;
    op_now = 0;
    head = malloc(sizeof(Node));
    head->next = head->prev = NULL;
    head->val = x;
    head->tag = op_now;
    cur = head;
    mid = head;
    node_num = 1;
  } else {
    cur->next = malloc(sizeof(Node));
    cur->next->val = x;
    cur->next->prev = cur;
    cur->next->next = NULL;
    cur->next->tag = op_now;
    cur = cur->next;
    node_num += 1;
    if (node_num % 2 == 1) {
      mid = mid->next;
    }
  }
}

void pop() {
  int tmp_tag;
  double val;
  if (head == NULL || node_num == 0) {
    return ;
  }
  tmp_tag = mid->tag;
  val = (double)mid->val;
  if (node_num == 1) {
    free(head);
    head = cur = mid = NULL;
    node_num = 0;
  } else if (node_num == 2) {
    head = head->next;
    head->next = head->prev = NULL;
    cur = head;
    free(mid);
    node_num -= 1;
    mid = head;
  } else {
    node_num -= 1;
    Node* destroy = mid;
    mid->prev->next = mid->next;
    mid->next->prev = mid->prev;
    if (node_num % 2 == 0) {
      mid = mid->prev;
    } else {
      mid = mid->next;
    }
    free(destroy);
  }
}

void IP2_sugoi() {
  op_now += 1;
  all_operation[op_now] = -1;
}

void programming_tanoshi(int k) {
  if (k == 1) {
    return ;
  }
  op_now += 1;
  all_operation[op_now] = k;
}

void KuoYangTeTe() {
  Node* run = head;
  while (run != NULL) {
    double tmp = (double)run->val;
    for (int i = run->tag+1; i <= op_now; i++) {
      if (all_operation[i] == -1) {
        tmp = floor(sqrt(tmp));
      } else {
        tmp = ceil(tmp/(double)all_operation[i]);
      }
      if ((int)tmp == 1) break;
    }
    run->val = (int)tmp;
    run = run->next;
  }
}
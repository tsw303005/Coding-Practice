#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void add_node(int n) {
  if (tree_head == NULL) {
    tree_head = malloc(sizeof(Tree_Node));
    tree_head->left = tree_head->right = NULL;
    tree_head->number = n;
    tree_head->parent = NULL;
  } else {
    Tree_Node* cur = tree_head;
    Tree_Node* temp = malloc(sizeof(Tree_Node));
    temp->left = temp->right = NULL;
    temp->number = n;
    while (1) {
      if (n >= cur->number && cur->right != NULL) {
        cur = cur->right;
      } else if (n < cur->number && cur->left != NULL) {
        cur = cur->left;
      } else if (n >= cur->number) {
        cur->right = temp;
        temp->parent = cur;
        break;
      } else {
        cur->left = temp;
        temp->parent = cur;
        break;
      }
    }
  }
}


void showtree(Tree_Node* treenow) {
  if (treenow) {
    showtree(treenow->left);
    printf("%d ", treenow->number);
    showtree(treenow->right);
  } else {
    return ;
  }
}
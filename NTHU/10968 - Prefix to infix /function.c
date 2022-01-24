#include "function.h"
#include <stdio.h>

void printInfix(Node *root) {
  if (root) {
    printInfix(root->left);
    printf("%c", root->data);
    if (root->right != NULL && (root->right->data == '|' || root->right->data == '&')) {
      printf("(");
      printInfix(root->right);
      printf(")");
    } else {
      printInfix(root->right);
    }
  }
}
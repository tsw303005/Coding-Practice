#include "function.h"

Node* createList() {
    Node* head = NULL;
    Node* cur = NULL;
    int t;

    while (1) {
        scanf("%d", &t);
        if (t == -1) break;
        else if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            head->data = t;
            head->next = NULL;
            cur = head;
        } else {
            cur->next = (Node*)malloc(sizeof(Node));
            cur->next->data = t;
            cur->next->next = NULL;
            cur = cur->next;
        }
    }
    return head;
}

void deleteNode(Node ** nd, int data) {
    Node* cur = (*nd);
    Node* prev = NULL;

    if (data == 1) {
        (*nd) = cur->next;
        free(cur);
    } else if (data > 1) {
        for (int i = 1; i < data && cur != NULL; i++, prev = cur, cur = cur->next);
        if (cur != NULL) {
            prev->next = cur->next;
            free(cur);
        }
    }
}
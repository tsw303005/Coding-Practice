#include "function.h"

// array max heap
Array_MAX_HEAP::Array_MAX_HEAP():MAX_HEAP() {
    for (int i = 0; i < 1025; i++) array[i] = -1;
}

void Array_MAX_HEAP::PUSH(const int& a) {
    this->Count += 1;
    this->array[this->Count] = a;

    // update the tree
    for (int i = this->Count; i / 2 >= 1 && array[i] > array[i/2]; i /= 2) {
        int change = array[i];
        array[i] = array[i/2];
        array[i/2] = change;
    }
}

int Array_MAX_HEAP::MAX() const {
    return this->array[1];
}

int Array_MAX_HEAP::POP() {
    int ans = this->array[1];
    if (ans == -1) return ans;

    this->array[1] = this->array[this->Count];
    this->array[this->Count] = -1;
    this->Count -= 1;
    int run = 1;
    int flag = 1;
    while (flag) {
        if (run*2+1 <= this->Count) {
            int index = (this->array[run*2] >= this->array[run*2+1]) ? run*2 : run*2+1;
            if (this->array[run] < this->array[index]) {
                int change = this->array[run];
                this->array[run] = this->array[index];
                this->array[index] = change;
                run = index;
            } else flag = 0;
        } else if (run*2 <= this->Count) {
            if (this->array[run] < this->array[run*2]) {
                int change = this->array[run];
                this->array[run] = this->array[run*2];
                this->array[run*2] = change;
                run = run*2;
            } else flag = 0;
        } else flag = 0;
    }
    return ans;
}

// link list max heap
List_MAX_HEAP::List_MAX_HEAP():MAX_HEAP() {
    root = nullptr;
}

void List_MAX_HEAP::PUSH(const int& a) {
    this->Count += 1;

    if (root == nullptr) {
        root = new ListNode(a);
    } else {
        ListNode *cur = nullptr;
        ListNode *par = this->findparent(this->Count, this->root);
        if (par->left) par->right = new ListNode(a), cur = par->right, cur->parent = par;
        else  par->left = new ListNode(a), cur = par->left, cur->parent = par;

        while (cur->parent != nullptr) {
            if (cur->value > cur->parent->value) {
                int change = cur->value;
                cur->value = cur->parent->value;
                cur->parent->value = change;
                cur = cur->parent;
            } else break;
        }
    }
}

int List_MAX_HEAP::MAX() const {
    return (this->root == nullptr) ? -1 : this->root->value;
}

int List_MAX_HEAP::POP() {
    int ans = (root == nullptr) ? -1 : this->root->value;
    if (ans == -1) return ans;

    ListNode *par = this->findparent(this->Count, this->root);
    this->Count -= 1;
    if (this->Count == 0) {
        delete this->root;
        this->root = nullptr;
    } else {
        ListNode *delete_node = nullptr;
        if (par->right) {
            delete_node = par->right;
            par->right = nullptr;
        } else {
            delete_node = par->left;
            par->left = nullptr;
        }
        this->root->value = delete_node->value;
        delete delete_node;
        
        ListNode *cur = this->root;
        int flag = 1;
        while (flag) {
            if (cur->right) {
                if (cur->right->value > cur->left->value && cur->right->value > cur->value) {
                    int change = cur->value;
                    cur->value = cur->right->value;
                    cur->right->value = change;
                    cur = cur->right;
                } else if (cur->left->value > cur->value) {
                    int change = cur->value;
                    cur->value = cur->left->value;
                    cur->left->value = change;
                    cur = cur->left;
                } else {
                    flag = 0;
                }
            } else if (cur->left) {
                if (cur->left->value > cur->value) {
                    int change = cur->value;
                    cur->value = cur->left->value;
                    cur->left->value = change;
                    cur = cur->left;
                } else {
                    flag = 0;
                }
            } else {
                flag = 0;
            }
        }
    }
    return ans;
}

void List_MAX_HEAP::deleteTree(ListNode* root) {}
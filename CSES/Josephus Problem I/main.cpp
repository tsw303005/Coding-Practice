// not pass

#include <iostream>

using namespace std;

typedef struct _node{ 
    _node *next;
    int num;
}Node;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int flag = 0;

    cin >> n;
    
    Node *cur = NULL;
    Node *head = NULL;
    Node *prev;

    head = new Node();
    head->next = NULL;
    cur = head;
    head->num = 1;

    for (int i = 2; i <= n; i++) {
        cur->next = new Node();
        cur->next->next = NULL;
        cur->next->num = i;
        cur = cur->next;
    }

    cur->next = head;

    while (cur->next != cur) {
        for (int i = 0; i < 2; i++) {
            prev = cur;
            cur = cur->next;
        }
        if (!flag) flag = 1;
        else cout << " ";
        cout << cur->num;

        prev->next = cur->next;
        delete cur;
        cur = prev;
    }

    if (flag) cout << " ";
    cout << cur->num << endl;

    return 0;
}
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int _ = 0; _ < n; _++) {
        int x;
        int a[40];
        a[0] = 0;

        scanf("%d", &x);

        for (int i = 1; i <= x; i++) {
            if (i == 1) a[i] = 1;
            else if (i == 2) a[i] = 2;
            else a[i] = a[i-1] + a[i-2];
        }
        printf("%d\n", a[x]);
    }

    return 0;
}
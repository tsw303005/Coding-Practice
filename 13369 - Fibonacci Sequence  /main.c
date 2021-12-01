#include <stdio.h>
#include <stdlib.h>
#include "function.h"

typedef long long ll;
int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);     // Get n and m
    ll A[4];
    A[0] = 1; A[1] = 1;
    A[2] = 1; A[3] = 0;             // Define what matrix A is
    ll *An = matrix_pow(A, n, m);   // Calculate A^n
    printf("%lld\n", An[2]);        // Fn = An[2][1]*F1 + An[2][2]*F0 = An[2][1] (F0=0, F1=1)
    return 0;
}

#include "function.h"
#include <stdlib.h>

ll* find(ll b, ll m) {
  if (b == 1) {
    ll *A = (ll*)malloc(sizeof(ll) * 4);
    A[0] = A[1] = A[2] = 1;
    A[3] = 0;
    return A;
  } else if (b % 2 == 0) {
    ll *A = find(b / 2, m);
    ll tmp[4];
    for (int i = 0; i < 4; i++) tmp[i] = A[i];
    A[0] = (tmp[0] * tmp[0] + tmp[1] * tmp[2]) % m;
    A[1] = (tmp[0] * tmp[1] + tmp[1] * tmp[3]) % m;
    A[2] = (tmp[2] * tmp[0] + tmp[3] * tmp[2]) % m;
    A[3] = (tmp[2] * tmp[1] + tmp[3] * tmp[3]) % m;
    return A;
  } else {
    ll *A = find((b - 1) / 2, m);
    ll tmp[4];
    for (int i = 0; i < 4; i++) tmp[i] = A[i];
    A[0] = (tmp[0] * tmp[0] + tmp[1] * tmp[2]) % m;
    A[1] = (tmp[0] * tmp[1] + tmp[1] * tmp[3]) % m;
    A[2] = (tmp[2] * tmp[0] + tmp[3] * tmp[2]) % m;
    A[3] = (tmp[2] * tmp[1] + tmp[3] * tmp[3]) % m;
    for (int i = 0; i < 4; i++) tmp[i] = A[i];
    A[0] = (tmp[0] + tmp[2]) % m;
    A[1] = (tmp[1] + tmp[3]) % m;
    A[2] = tmp[0];
    A[3] = tmp[1];
    return A;
  }
}

ll* matrix_pow(ll *A, ll b, ll m) {
  if (b == 1) {
    for (int i = 0; i < 4; i++) A[i] %= m;
    return A;
  } else if (b == 0) {
    for (int i = 0; i < 4; i++) A[i] = 0;
    return A;
  } else {
    ll *tmp = find(b, m);
    for (int i = 0; i < 4; i++) tmp[i] %= m;
    return tmp;
  }
}
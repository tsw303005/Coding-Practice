#include <iostream>

using namespace std;

unsigned long long  fibonacci(unsigned long long  n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    unsigned long long  n, t;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        cout << fibonacci(t) << endl;
    }

    return 0;
}
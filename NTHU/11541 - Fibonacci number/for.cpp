#include <iostream>

using namespace std;

unsigned long long fibonacci(unsigned long long  n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    else {
        unsigned long long prev_1 = 1, prev_2 = 1;
        unsigned long long now;
        for (unsigned long long i = 3; i <= n; i++) {
            now = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = now;
        }
        return now;
    }
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
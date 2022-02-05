#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}
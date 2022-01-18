#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    unsigned long n;
    unsigned long ans = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0) ans += i / 5, cout << (i / 5) << endl;;
    }
    cout << ans << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned long long n, ans, t, prev;

    cin >> n;
    ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (i != 0 && t < prev) {
            ans = ans + (prev - t);
            t = prev;
        }
        prev = t;
    }

    cout << ans << "\n";
    return 0;
}
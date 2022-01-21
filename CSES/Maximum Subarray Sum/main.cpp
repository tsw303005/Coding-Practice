#include <iostream>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long int n, t, now, ans;

    cin >> n;
    now = 0;
    ans = numeric_limits<long long int>::min();
    for (int i = 0; i < n; i++) {
        cin >> t;
        now += t;
        if (now < 0) now = t;
        if (now > ans) ans = now;
        if (now < 0) now = 0;
    }

    cout << ans << "\n";
    return 0;
}
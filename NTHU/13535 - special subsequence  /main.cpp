#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, a, left, ans;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        left = 0;
        unordered_map<int, int> m;
        ans = 0;

        for (int j = 1; j <= n; j++) {
            cin >> a;
            if (m[a * 2] > left) left = m[a * 2];
            if (a % 2 == 0 && m[a / 2] > left) left = m[a / 2];
            m[a] = j;

            ans = max(ans, j - left);
        }

        cout << ans << '\n';
    }

    return 0;
}
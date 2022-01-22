#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b, ans, now;
    multiset<int> arrive;
    multiset<int> en;

    cin >> n;
    ans = 0;
    now = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arrive.insert(a);
        en.insert(b);
    }

    while (!arrive.empty()) {
        if (*arrive.begin() <= *en.begin()) {
            now += 1;
            arrive.erase(arrive.begin());
        } else {
            now -= 1;
            en.erase(en.begin());
        }
        ans = (now > ans) ? now : ans;
    }
    cout << ans << '\n';

    return 0;
}
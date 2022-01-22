#include <iostream>
#include <map>


using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<long long int, int> m;
    long long int n, sum, t;
    long long int now = 0;
    long long int ans = 0;

    cin >> n >> sum;
    for (long long int i = 0; i < n; i++) {
        cin >> t;
        if (m.find(now) == m.end()) {
            m[now] = 1;
        } else {
            m[now] += 1;
        }
        now += t;
        if (m.find(now - sum) != m.end()) ans += m[now - sum];
    }

    cout << ans << "\n";

    return 0;
}
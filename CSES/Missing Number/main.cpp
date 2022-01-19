#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    unsigned long long n, t, k, ans;
    cin >> n;

    ans = (1 + n) * n / 2;
    k = 0;

    for (unsigned long long i = 0; i < n - 1; i++) {
        cin >> t;
        k += t;
    }

    cout << ans - k << endl;


    return 0;
}
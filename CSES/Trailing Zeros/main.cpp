#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    unsigned long n;
    unsigned long ans = 0;

    cin >> n;
    for (int i = 5; n / i >= 1; i *= 5) {
        ans += (n / i);
    }
    cout << ans << endl;

    return 0;
}
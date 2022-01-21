#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned long long  n, a, b, ans;

    cin >> n;


    for (unsigned long long  i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b) {
            if (a % 2 == 1) {
                ans = (a - 1) * (a - 1) + b;
            } else {
                ans = a * a - b + 1;
            }
        } else if (a < b){
            if (b % 2 == 1) {
                ans = b * b - a + 1;
            } else {
                ans = (b - 1) * (b - 1) + a;
            }
        } else {
            ans = a * a - b + 1;
        }

        cout << ans << "\n"; 
    }


    return 0;
}
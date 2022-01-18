#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    double a, b;
    double x, y;


    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (b > a) cout << "impossible\n";
        else {
            x = (a + b) / 2;
            y = (a - b) / 2;
            if ((int)x - x != 0 || (int)y - y != 0) cout << "impossible\n";
            else cout << (int)x << " " << (int)y << "\n";
        }
    }

    return 0;
}
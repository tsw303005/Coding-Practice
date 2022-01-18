#include <iostream>
#include <math.h>

using namespace std;

unsigned long ans = 0;

void hanoi(int left, int middle, int right, int now) {
    if (now > 0) {
        hanoi(left, right, middle, now-1);
        cout << left << " " << right << "\n";
        hanoi(middle, left, right, now-1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    
    ans = pow(2, n) - 1;
    cout << ans << "\n";

    hanoi(1, 2, 3, n);

    return 0;
}
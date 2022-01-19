#include <iostream>

using namespace std;

int arr[200005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t;
    int ans = 1;
    
    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        arr[t] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] < arr[i - 1]) ans += 1;
    }

    cout << ans << endl;

    return 0;
}
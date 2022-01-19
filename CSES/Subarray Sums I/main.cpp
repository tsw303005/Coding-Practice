#include <iostream>

using namespace std;

unsigned long long arr[200005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned long long n, sum, left, ans, t;

    ans = 0;
    cin >> n >> sum;
    arr[0] = 0;
    left = 0;

    for (unsigned long long i = 1; i <= n; i++) {
        cin >> t;
        arr[i] = arr[i - 1] + t;
        
        while (left < i) {
            if (arr[i] - arr[left] == sum) {
                ans += 1;
                break;
            }
            else if (arr[i] - arr[left] > sum) left += 1;
            else break;
        }
    }

    cout << ans << endl;

    return 0;
}
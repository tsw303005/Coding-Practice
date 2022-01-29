/*

因為 (a[i] - a[j])^2 = (i -j)^2 可以整理成 (a[i] - a[j] - i + j)(a[i] - a[j] + i - j) = 0
可以再整理成 (a[i] - i - a[j] + j)(a[i] + i - a[j] - j) = 0
這樣代表我每次只要紀錄 a[j] - j 以及 a[j] + j
然後每次 a[i] - i 往前檢查前面有沒有 a[j] - j 的值是一樣的
以及 a[i] + i 往前檢查有沒有 a[j] + j 的值是一樣的
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_map<int, int> m_add, m_sub;

    long long int n, t, ans;
    ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t;

        ans += m_sub[t - i];
        ans += m_add[t + i];
        m_sub[t - i] += 1;
        m_add[t + i] += 1;
    }
    cout << ans << "\n";

    return 0;
}
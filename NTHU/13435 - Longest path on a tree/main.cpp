#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<bool> check;
vector<vector<int> > V;

int ans = 0;
int endpoint = 1;

void dfs(int u, int value) {
    check[u] = true;

    if (value > ans) {
        ans = value;
        endpoint = u;
    }

    for (auto i : V[u]) {
        if (!check[i]) {
            dfs(i, value + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, u, v;

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> n;
        
        V.clear();
        check.clear();
        V.resize(n+1);
        check.resize(n+1);
        ans = 0;
        endpoint = 1;

        for (int i = 0; i < n-1; i++) {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        // first pass
        fill(check.begin(), check.end(), false);
        dfs(1, 0);


        fill(check.begin(), check.end(), false);
        dfs(endpoint, 0);

        cout << ans << endl;
    }

    return 0;
}
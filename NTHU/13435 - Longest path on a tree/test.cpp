#include <iostream>
#include <vector>
#include <utility>
#define endl '\n'

using namespace std;

typedef pair<int, int> result;

vector<bool> check;
vector<vector<int> > V;

result dfs(int u) {
    result re;

    re.first = re.second = 0;
    check[u] = true;

    for (auto &i : V[u]) {
        if (!check[i]) {
            result get = dfs(i);
            re.second = max(re.second, re.first + get.first);
            re.second = max(re.second, get.second);
            re.first = max(re.first, get.first);
        }
    }

    re.first += 1;
    return re;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, u, v, n;

    cin >> T;

    while (T--) {
        cin >> n;

        V.clear();
        check.clear();

        V.resize(n+1);
        check.resize(n+1);

        fill(check.begin(), check.end(), false);

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        cout << dfs(1).second << endl;
    }

    return 0;
}
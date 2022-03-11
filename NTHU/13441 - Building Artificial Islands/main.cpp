#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

vector<bool> check;
vector<vector<node> > V;

vector<int> dfs(int u, int value) {
    vector<int> result(4, 0);
    vector<int> tmp;
    check[u] = true;

    for (auto v : V[u]) {
        if (!check[v.first]) {
            vector<int> re = dfs(v.first, v.second);

            tmp.clear();
            tmp = {
                result[2], result[3], re[2], re[3],
                result[0] + re[0], result[0] + re[1],
                result[1] + re[0], result[1] + re[1]
            };
            sort(tmp.begin(), tmp.end(), greater<int>());
            result[2] = tmp[0];
            for (int i = 1; i < 8; i++) {
                if (tmp[i] != tmp[0]) {
                    result[3] = tmp[i];
                    break;
                }
            }

            tmp.clear();
            tmp = {result[0], result[1], re[0], re[1]};
            sort(tmp.begin(), tmp.end(), greater<int>());
            result[0] = tmp[0];
            for (int i = 1; i < 4; i++) {
                if (tmp[i] != tmp[0]) {
                    result[1] = tmp[i];
                    break;
                }
            }
        }
    }
    
    if (result[0] == 0) result[0] = value;
    else result[0] += value, result[1] += value;

    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, u, v, t;

    cin >> n;
    check.resize(n+1);
    fill(check.begin(), check.end(), false);

    V.resize(n);

    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> t;
        V[u].push_back({v, t});
        V[v].push_back({u, t});
    }

    cout << dfs(0, 0)[3] << endl;

    return 0;
}
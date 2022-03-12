#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

vector<vector<int> > V;
vector<bool> check;
queue<int> Q;

int endpoint;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, u, v, size;

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> n;

        V.clear();
        V.resize(n+1);
        check.clear();
        check.resize(n+1);
        fill(check.begin(), check.end(), false);

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            V[u].push_back(v);
            V[v].push_back(u);
        }

        endpoint = 1;
        ans = 0;
        Q.push(1);

        while (!Q.empty()) {
            size = Q.size();
            endpoint = Q.front();
            for (int i = 0; i < size; i++) {
                int now = Q.front();
                Q.pop();

                for (auto q : V[now]) {
                    if (!check[q]) Q.push(q), check[q] = true;
                }
            }
        }

        Q.push(endpoint);
        fill(check.begin(), check.end(), false);

        while (!Q.empty()) {
            size = Q.size();
            ans += 1;
            for (int i = 0; i < size; i++) {
                int now = Q.front();
                Q.pop();

                for (auto q : V[now]) {
                    if (!check[q]) Q.push(q), check[q] = true;
                }
            }
        }

        cout << ans - 1 << endl;
    }
}
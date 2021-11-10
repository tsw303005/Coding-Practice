#include <iostream>
#include <set>

using namespace std;

set <int> all_node[5005];
set <int> leaf;

int main() {
  int n, u, v, neighbor, removed_node;
  
  cin >> n;
  for (int i = 1; i <= n-1; i++) {
    cin >> u >> v;
    all_node[u].insert(v);
    all_node[v].insert(u);
  }

  for (int i = 1; i <= n; i++) {
    if (all_node[i].size() == 1) {
      leaf.insert(i);
    }
  }

  for (int i = 1; i <= n-2; i++) {
    removed_node = *(leaf.begin());
    neighbor = *(all_node[removed_node].begin());
    leaf.erase(removed_node);
    all_node[removed_node].clear();
    all_node[neighbor].erase(removed_node);
    if (all_node[neighbor].size() == 1) {
      leaf.insert(neighbor);
    }
    cout << neighbor << ' ';
  }
  cout << endl;

  return 0;
}
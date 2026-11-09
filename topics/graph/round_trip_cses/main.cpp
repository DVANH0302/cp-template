#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(it, v) for (auto &it : v)
#define all(v) (v).begin(), (v).end()

const int mod = 1000000000 + 7;

int n, m;
vector<vector<int>> g;
vector<int> path;
vector<int> visited;

int dfs(int node, int prev) {

  if (visited[node] == 1) {
    path.push_back(node);
    return node;
  }

  visited[node] = 1;

  for (auto nb : g[node]) {
    if (nb == prev)
      continue;

    int res = dfs(nb, node);

    if (res > 0) {
      path.push_back(node);
      if (node != res) {
        return res;
      } else {
        return 0;
      }
    } else if (res == 0) {
      return res;
    }
  }
  return -1;
}

void solve() {
  cin >> n >> m;
  g = vector<vector<int>>(n + 1, vector<int>());
  path = vector<int>();
  visited = vector<int>(n + 1, 0);
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i < n + 1; i++) {

    if (visited[i] != 0)
      continue;

    int res = dfs(i, -1);
    if (res == 0) {
      reverse(path.begin(), path.end());
      cout << path.size() << "\n";
      for (auto node : path) {
        cout << node << " ";
      }
      return;
    }
  }

  cout << "IMPOSSIBLE\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // int t;
  // cin >> t;
  // while (t--)

  solve();
}
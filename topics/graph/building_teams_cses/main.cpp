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
vector<int> color;

bool dfs(int node) {
  for (auto nb : g[node]) {
    if (color[nb] == color[node]) {
      return false;
    }

    if (color[nb] == 0) {
      color[nb] = color[node] == 1 ? 2 : 1;
      bool res = dfs(nb);

      if (!res) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  cin >> n >> m;
  g = vector<vector<int>>(n + 1, vector<int>());
  color = vector<int>(n + 1, 0);
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i < n + 1; i++) {
    if (color[i] == 0) {
      color[i] = 1;
      bool res = dfs(i);
      if (!res) {
        cout << "IMPOSSIBLE\n";
        return;
      }
    }
  }

  for (int i = 1; i < n + 1; i++) {
    cout << color[i] << " ";
  }
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
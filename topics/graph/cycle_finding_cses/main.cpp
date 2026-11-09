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

const ll inf = 1e15;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> g(n + 1);
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, inf));

  for (int node = 1; node <= n; node++) {
    dp[0][node] = 0;
  }

  int u, v, w;

  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g[v].push_back({u, w});
  }

  for (int e = 1; e <= n; e++) {
    for (int node = 1; node <= n; node++) {
      for (auto [nb, nbw] : g[node]) {

        if (dp[e][node] == inf) {
          dp[e][node] = dp[e - 1][node];
        }

        dp[e][node] = min(dp[e - 1][node], dp[e - 1][nb] + nbw);
      }
    }
  }

  int thisNode = 0;
  vector<int> cycle_node(n + 1, 0);

  for (int node = 1; node <= n; node++) {
    if (dp[n][node] < dp[n - 1][node]) {
      cycle_node[node] = 1;
      thisNode = node;
    }
  }

  if (thisNode == 0) {
    cout << "NO\n";
    return;
  }

  vector<int> visited(n + 1, 0);
  int cur = thisNode;
  stack<int> s;
  s.push(cur);
  visited[thisNode] = 1;

  while (!s.empty()) {
    int node = s.top();
    s.pop();
    cout << node << " ";

    for (auto [nb, nb_w] : g[node]) {
      if (cycle_node[nb] == 0 || visited[nb] == 1)
        continue;

      visited[nb] = 1;
      s.push(nb);
    }
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
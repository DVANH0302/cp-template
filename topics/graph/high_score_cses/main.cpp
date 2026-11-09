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

const ll inf = 1e18;

void solve() {

  int n, m;
  cin >> n >> m;

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, inf));

  dp[0][1] = 0;

  vector<vector<array<int, 2>>> g(n + 1);

  int a, b, x;
  for (int i = 0; i < m; i++) {

    cin >> a >> b >> x;
    g[b].push_back({a, -x});
  }

  vector<int> reach(n + 1, 0);
  queue<int> q;
  reach[n] = 1;
  q.push(n);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto [nb, nbw] : g[node])
      if (!reach[nb]) {
        reach[nb] = 1;
        q.push(nb);
      }
  }

  for (int e = 1; e <= n; e++) {
    for (int v = 1; v <= n; v++) {
      dp[e][v] = dp[e - 1][v];
      for (auto [u, w] : g[v])
        if (dp[e - 1][u] < inf)
          dp[e][v] = min(dp[e][v], dp[e - 1][u] + w);
    }
  }

  for (int v = 1; v <= n; v++) {
    if (dp[n][v] < dp[n - 1][v] && reach[v]) {
      cout << -1 << "\n";
      return;
    }
  }

  cout << -dp[n - 1][n] << "\n";
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
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

ll dp[501][501];

void solve() {

  int n, m, q;
  cin >> n >> m >> q;

  rep(i, 1, n + 1) {
    rep(j, 1, n + 1) {
      if (i == j)
        dp[i][j] = 0;
      else {
        dp[i][j] = inf;
      }
    }
  }

  int u, v, w;
  rep(i, 0, m) {
    cin >> u >> v >> w;
    dp[u][v] = min(dp[u][v], (ll)w);
    dp[v][u] = min(dp[v][u], (ll)w);
  }

  for (int k = 1; k < n + 1; k++) {
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int v1, v2;
  rep(i, 0, q) {
    cin >> v1 >> v2;

    ll length = dp[v1][v2] == inf ? -1 : dp[v1][v2];

    cout << length << "\n";
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
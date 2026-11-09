#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

const int MOD = 1000000000 + 7;

int dp[100001][101];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (auto &item : x) {
    cin >> item;
  }

  for (int j = 0; j < m + 1; j++) {
    dp[n][j] = 1;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m; j >= 1; j--) {
      if (x[i] != 0) {
        if (abs(x[i] - j) > 1) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = (dp[i][j] + dp[i + 1][x[i]]) % MOD;
        }
      } else {
        if (j - 1 >= 1) {
          dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
        }
        if (j + 1 <= m) {
          dp[i][j] = (dp[i][j] + dp[i + 1][j + 1]) % MOD;
        }

        dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
      }
    }
  }

  ll res = 0;
  if (x[0] != 0)
    res = dp[1][x[0]];
  else
    for (int v = 1; v <= m; v++)
      res += dp[1][v];
  res %= MOD;

  cout << res << "\n";
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
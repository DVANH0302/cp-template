#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

ll dp[1000001];
ll coins[101];

void solve() {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  fill(dp, dp + x + 1, INT_MAX);
  dp[x] = 0;

  for (int i = x - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {

      if (i + coins[j] <= x)
        dp[i] = min(dp[i], 1 + dp[i + coins[j]]);
    }
  }

  int res;

  res = dp[0] != INT_MAX ? dp[0] : -1;

  // for (int i = 0; i <= x; i++) {
  //   cout << dp[i] << " ";
  // }
  // cout << "\n";

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
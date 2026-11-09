#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;
const int MOD = 1000000000 + 7;

ll dp[501][62626];

void solve() {
  int n;
  cin >> n;

  ll total = (ll)n * (n + 1) / 2;

  if (total % 2 == 1) {
    cout << 0 << endl;
    return;
  }

  ll target = total / 2;

  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < target + 1; j++) {
      dp[i][j] = dp[i - 1][j] % MOD;

      if (j - i >= 0) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
      }
    }
  }

  cout << dp[n][target] * ((MOD + 1) / 2) % MOD << "\n";
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
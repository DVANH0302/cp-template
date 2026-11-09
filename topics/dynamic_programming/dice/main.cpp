#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

ll dp[1000001];
ll MOD = pow(10, 9) + 7;

void solve() {
  memset(&dp, 0, sizeof(dp));
  int n;
  cin >> n;

  dp[n] = 1;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= 6; j++) {
      if (i + j <= n) {
        dp[i] = (dp[i] + dp[i + j]) % MOD;
      }
    }
  }

  cout << dp[0] << "\n";
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
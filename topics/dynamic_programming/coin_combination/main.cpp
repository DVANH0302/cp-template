#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

const ll MOD = 1000000007;

int coins[100];
ll dp[1000001];

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  dp[x] = 1;
  for (int i = x - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i + coins[j] <= x) {
        dp[i] = (dp[i] + dp[i + coins[j]]) % MOD;
      }
    }
  }

  cout << dp[0] << '\n';
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
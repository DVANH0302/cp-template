#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

const ll MOD = 1000000000 + 7;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (auto &c : coins) {
    cin >> c;
  }

  vector<int> dp(x + 1, 0);
  dp[x] = 1;

  for (auto c : coins) {
    for (int i = x - 1; i >= 0; i--) {
      if (i + c <= x) {
        dp[i] = (dp[i] + dp[i + c]) % MOD;
      }
    }
    // dbg(c);
    // dbg(dp);
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
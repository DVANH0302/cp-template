#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

const ll INF = 1000000000000000000;

bool valid(int i, int j) {
  while (i > 0) {
    if (j == i % 10) {
      return true;
    }
    i /= 10;
  }
  return false;
}

void solve() {

  int n;
  cin >> n;

  vector<ll> dp(n + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i - j >= 0 && valid(i, j)) {
        dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
  }

  cout << dp[n] << "\n";
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
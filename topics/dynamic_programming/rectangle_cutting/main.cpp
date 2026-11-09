#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

const int INF = 1000000000;

ll memo[501][501];
// ll dp[501][501];

ll dp(ll a, ll b) {
  if (a == b)
    return 0;

  if (memo[a][b] != 0) {
    return memo[a][b];
  }

  ll min_move = INF;
  for (int i = 1; i < a; i++) {
    min_move = min(min_move, dp(i, b) + dp(a - i, b));
  }
  for (int j = 1; j < b; j++) {
    min_move = min(min_move, dp(a, j) + dp(a, b - j));
  }
  memo[a][b] = min_move + 1;

  return min_move + 1;
}

void solve() {
  ll a, b;
  cin >> a >> b;

  cout << dp(a, b) << "\n";
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
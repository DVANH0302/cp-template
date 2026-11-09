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

const int inf = 1000000000;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  trav(x, h) cin >> x;
  vector<int> dp(n, inf);
  dp[0] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = max(0, i - k); j < i; j++) {
      dp[i] = min(dp[i], abs(h[i] - h[j]) + dp[j]);
    }
  }

  cout << dp[n - 1] << "\n";
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
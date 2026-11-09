#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  for (auto &hi : h) {
    cin >> hi;
  }

  for (auto &si : s) {
    cin >> si;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = x - 1; j >= 0; j--) {
      dp[i][j] = dp[i + 1][j];

      if (j + h[i] <= x) {
        dp[i][j] = max(dp[i][j], s[i] + dp[i + 1][j + h[i]]);
      }
    }
  }

  cout << dp[0][0] << "\n";
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
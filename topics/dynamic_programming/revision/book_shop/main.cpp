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
#define mod 1000000000 + 7

int dp[1001][100001];

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);
  trav(hi, h) cin >> hi;
  trav(si, s) cin >> si;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < x + 1; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j - h[i - 1] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
      }
    }
  }

  int max_page = 0;
  rep(i, 0, x + 1) { max_page = max(max_page, dp[n][i]); }

  cout << max_page << "\n";
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
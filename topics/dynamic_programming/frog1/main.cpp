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
  int n;
  cin >> n;
  vector<int> h(n);
  vector<int> dp(n, inf);
  trav(it, h) { cin >> it; }
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  rep(i, 2, n) {
    int c1 = abs(h[i] - h[i - 1]);
    int c2 = abs(h[i] - h[i - 2]);

    dp[i] = min(dp[i - 2] + c2, dp[i - 1] + c1);
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
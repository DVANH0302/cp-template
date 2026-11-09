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

const int mod = 1000000000 + 7;
ll inf = 10000000000;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> w(n);
  vector<array<ll, 2>> dp(1 << n);
  trav(it, w) cin >> it;
  dp[0] = {1, 0};

  rep(mask, 1, 1 << n) {

    dp[mask] = {n, inf};

    for (int i = 0; i < n; i++) {

      if (mask & 1 << i) {

        auto [ride, load] = dp[mask & ~(1 << i)];

        if (load + w[i] > x) {
          ride++;
          // load = w[i];
          load = w[i];
        } else {
          load += w[i];
        }

        if (ride < dp[mask][0]) {
          dp[mask] = {ride, load};
        } else if (ride == dp[mask][0]) {
          dp[mask] = {ride, min(dp[mask][1], load)};
        }
      }
    }
  };

  cout << dp[(1 << n) - 1][0] << "\n";
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
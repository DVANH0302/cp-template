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

ll dp[100000][101]; // number of way to finish first ith elements where the
                    // current element is j

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  trav(xi, x) cin >> xi;

  if (x[0] == 0) {
    rep(j, 1, m + 1) { dp[0][j] = 1; }
  } else {
    dp[0][x[0]] = 1;
  }

  rep(i, 1, n) {
    rep(j, 1, m + 1) {
      if (x[i] != 0 && x[i] != j)
        continue;

      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
    }
  }
  ll sum = 0;
  rep(j, 1, m + 1) { sum = (sum + dp[n - 1][j]) % mod; }

  cout << sum << "\n";
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
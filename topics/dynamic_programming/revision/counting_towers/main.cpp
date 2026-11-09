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

ll dp[1000001][2];

void init() {
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 1; i < 1000001; i++) {
    dp[i][0] = (dp[i - 1][1] + 2 * dp[i - 1][0]) % mod;
    dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % mod;
  }
}

void solve() {
  int n;
  cin >> n;

  cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int t;
  cin >> t;
  while (t--)

    solve();
}
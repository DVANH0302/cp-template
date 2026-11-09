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

ll dp[1001][(1 << 10) + 1];

void solve() {
  int n, m;
  cin >> n >> m;

  dp[n - 1][(1 << n) - 1] = 1;

  rep(row, 0, m) {
    for (int mask = 1 << n - 1; mask >= 0; mask--) {
    }
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
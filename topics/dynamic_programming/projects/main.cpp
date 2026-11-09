#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> project(n);
  for (int i = 0; i < n; i++) {
    cin >> project[i][0] >> project[i][1] >> project[i][2];
  }

  sort(project.begin(), project.end(),
       [](const array<int, 3> &a, const array<int, 3> &b) {
         return a[0] < b[0];
       });
  /*
    dp[i] += dp[next]
  */

  vector<ll> dp(n + 1, 0);

  for (int i = n - 1; i >= 0; i--) {

    dp[i] = max(dp[i], dp[i + 1]);

    auto rit =
        upper_bound(project.begin() + i, project.end(), project[i][1],
                    [](int val, const array<int, 3> &x) { return val < x[0]; });

    int rid = rit - project.begin();

    dp[i] = max(dp[i], dp[rid] + project[i][2]);
  };

  cout << dp[0] << "\n";
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
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

ll dp[5001][5001]; // min cost to make first i chars equal first j chars

void solve() {
  string s1, s2;
  cin >> s1;
  cin >> s2;

  int n1 = (int)s1.size();
  int n2 = (int)s2.size();

  rep(i, 1, n1 + 1) { dp[i][0] = i; }
  rep(j, 1, n2 + 1) { dp[0][j] = j; }

  for (int i = 1; i < n1 + 1; i++) {
    for (int j = 1; j < n2 + 1; j++) {

      // still considering s1 and s2
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
      }
    }
  }

  cout << dp[n1][n2] << "\n";
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
#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;
using vii = vector<vector<int>>;
using vll = vector<vector<ll>>;

const int MOD = 1000000000 + 7;
const int N = 1000000;

ll dp[N][2];

void init() {

  dp[0][0] = 1;
  dp[0][1] = 1;

  for (int i = 1; i < N; i++) {
    dp[i][0] = (dp[i - 1][1] % MOD + 2 * (dp[i - 1][0] % MOD)) % MOD;
    dp[i][1] = (dp[i - 1][0] % MOD + 4 * (dp[i - 1][1] % MOD)) % MOD;
  }
}

void solve() {
  ll n;
  cin >> n;
  cout << (dp[n - 1][0] % MOD + dp[n - 1][1] % MOD) % MOD << "\n";
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
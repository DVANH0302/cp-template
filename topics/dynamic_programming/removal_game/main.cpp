#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

ll dp[5000][5000];
int x[5000];

void display(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  ll total = 0;
  for (int i = 0; i < n; i++) {
    total += x[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i][i] = x[i];
  }

  for (int l = n - 2; l >= 0; l--) {
    for (int r = l + 1; r < n; r++) {
      dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
    }
  }

  cout << (ll)((total + dp[0][n - 1]) / 2) << "\n";
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
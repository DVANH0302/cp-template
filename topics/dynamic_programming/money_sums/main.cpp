#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

int dp[101][100001];
int coins[100];

void display(int n, int total) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < total + 1; j++) {
      cout << dp[i][j] << " ";
    }

    cout << endl;
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  int total = 0;
  for (int i = 0; i < n; i++) {
    total += coins[i];
  }

  for (int i = 0; i < n + 1; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < total + 1; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - coins[i - 1] >= 0) {
        dp[i][j] = dp[i][j] | dp[i - 1][j - coins[i - 1]];
      }
    }
  }
  // display(n, total);
  int count = 0;
  for (int j = 1; j < total + 1; j++) {
    if (dp[n][j] == 1) {
      count++;
    }
  }
  cout << count << "\n";

  for (int j = 1; j < total + 1; j++) {
    if (dp[n][j] == 1) {
      cout << j << " ";
    }
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
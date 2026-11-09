#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void display(vector<vector<int>> &grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << "-1\n";
    return;
  }

  vector<vector<int>> grid(n, vector<int>(n));

  int idx = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = idx;
      if (idx + 2 > n * n) {
        idx = 2;
      } else {
        idx += 2;
      }
    }
  }
  display(grid, n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)

    solve();
}
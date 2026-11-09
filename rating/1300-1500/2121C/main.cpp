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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  int max_a = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      max_a = max(a[i][j], max_a);
    }
  }

  vector<int> rows(n, 0);
  vector<int> cols(m, 0);
  int max_count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == max_a) {
        max_count++;
        rows[i]++;
        cols[j]++;
      }
    }
  }
  // dbg(a);
  // dbg(rows);
  // dbg(cols);
  // dbg(max_count);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int count = 0;
      if (a[i][j] == max_a) {
        count--;
      }
      count += rows[i] + cols[j];
      if (count == max_count) {
        cout << max_a - 1 << "\n";
        return;
      }
    }
  }

  cout << max_a << "\n";
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
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void solve() {
  int n, k;
  cin >> k >> n;
  vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

  vector<int> lines(n);
  for (int i = 0; i < k; i++) {
    for (auto &num : lines) {
      cin >> num;
    }

    for (int i = 0; i < sz(lines); i++) {
      for (int j = i + 1; j < sz(lines); j++) {
        if (grid[lines[i]][lines[j]] == 0) {
          grid[lines[i]][lines[j]] = 1;
          grid[lines[j]][lines[i]] = -1;
        } else if (grid[lines[i]][lines[j]] == -1) {
          grid[lines[i]][lines[j]] = -2;
          grid[lines[j]][lines[i]] = -2;
        }
      }
    }
  }
  int ones = 0;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      if (grid[i][j] == 1)
        ones++;
    }
  }
  cout << ones << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
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

void display(vector<vector<char>> res, int m, int n, int k) {
  for (int i = 0; i < m * k; i++) {
    for (int j = 0; j < n * k; j++) {
      cout << res[i][j];
    }
    cout << endl;
  }
}

void solve() {
  int m, n, k;
  string line;
  getline(cin, line);
  stringstream ss(line);
  ss >> m >> n >> k;
  vector<vector<char>> grid(m, vector<char>(n));
  vector<vector<char>> res(k * m, vector<char>(k * n, '.'));

  int i = 0;
  while (getline(cin, line)) {
    for (int j = 0; j < line.size(); j++) {
      grid[i][j] = line[j];
    }
    i += 1;
  };
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {

      // copy right side
      for (int y = i * k; y < (i + 1) * k; y++)
        for (int x = j * k; x < (j + 1) * k; x++) {
          res[y][x] = grid[i][j];
        }

      // if (i == 0 && j == 2)
      //   display(res, m, n, k);
    }
  }
  display(res, m, n, k);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
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

vector<int> dxs = {-1, 0, 1, 0};
vector<int> dys = {0, -1, 0, 1};
int n, m;

void dfs(int x, int y, vector<vector<int>> &visited, vector<string> &g) {

  for (int i = 0; i < 4; i++) {
    int nx = x + dxs[i];
    int ny = y + dys[i];

    if (0 <= nx && nx < n && 0 <= ny && ny < m && g[nx][ny] == '.' &&
        visited[nx][ny] == 0) {
      visited[nx][ny] = 1;
      dfs(nx, ny, visited, g);
    }
  }
}

void solve() {
  cin >> n >> m;
  vector<string> g(n);
  trav(gi, g) { cin >> gi; }

  vector<vector<int>> visited(n, vector<int>(m, 0));
  int rooms = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '.' && visited[i][j] == 0) {
        visited[i][j] = 1;
        rooms++;
        dfs(i, j, visited, g);
      }
    }
  }

  cout << rooms << "\n";
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
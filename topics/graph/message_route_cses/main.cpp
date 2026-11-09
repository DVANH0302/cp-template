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

const int inf = 100000000;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>());

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> distance(n + 1, inf);
  distance[1] = 0;
  queue<array<int, 2>> q;
  q.push({1, 0});

  while (!q.empty()) {
    auto [node, cost] = q.front();
    q.pop();

    for (auto nb : g[node]) {
      if (distance[nb] == inf) {
        distance[nb] = cost + 1;
        q.push({nb, cost + 1});
      }
    }
  }

  if (distance[n] == inf) {
    cout << "IMPOSSIBLE" << "\n";
    return;
  }

  vector<int> path;
  int cur = n;
  path.push_back(cur);

  while (cur != 1) {

    for (auto nb : g[cur]) {
      if (distance[nb] == distance[cur] - 1) {
        path.push_back(nb);
        cur = nb;
      }
    }
  }

  reverse(path.begin(), path.end());

  cout << path.size() << "\n";

  for (auto node : path) {
    cout << node << " ";
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
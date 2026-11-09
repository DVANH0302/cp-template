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
const ll inf = 1e15;

void solve() {
  int n, m;
  cin >> n >> m;
  int u, v, w;

  vector<vector<array<ll, 2>>> g(n + 1, vector<array<ll, 2>>());
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }

  priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
  pq.push({0, 1});

  vector<ll> dist(n + 1, inf);
  dist[1] = 0;
  while (!pq.empty()) {
    auto [cost, node] = pq.top();
    pq.pop();

    if (cost > dist[node])
      continue;

    for (auto [nb, nbw] : g[node]) {
      if (cost + nbw < dist[nb]) {
        dist[nb] = cost + nbw;
        pq.push({cost + nbw, nb});
      }
    }
  }

  rep(i, 1, n + 1) { cout << dist[i] << " "; }
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
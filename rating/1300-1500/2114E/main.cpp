#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> val(n + 1, 0);
  for (int i = 1; i < n + 1; i++) {
    cin >> val[i];
  }

  vector<vector<ll>> g = vector<vector<ll>>(n + 1, vector<ll>());
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<ll> t(n + 1, 0);
  t[1] = val[1];

  vector<ll> visit(n + 1, 0);
  visit[1] = 1;

  deque<pair<ll, pair<ll, ll>>> q;
  q.push_back({1, {0, val[1]}}); // (node, cost_min, cost_max)
  while (!q.empty()) {
    auto p = q.front();
    q.pop_front();
    ll node = p.first, cost_min = p.second.first, cost_max = p.second.second;

    for (auto nb : g[node]) {
      if (visit[nb] == 1) {
        continue;
      };
      visit[nb] = 1;
      t[nb] = max(val[nb] - cost_min, val[nb]);
      q.push_back({nb,
                   {min(val[nb], val[nb] - cost_max),
                    max(val[nb], val[nb] - cost_min)}});
    }
  }

  for (int i = 1; i < n + 1; i++) {
    cout << t[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)

    solve();
}
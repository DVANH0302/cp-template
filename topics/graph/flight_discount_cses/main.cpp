#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

using T = tuple<ll, int, int>;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(it, v) for (auto &it : v)
#define all(v) (v).begin(), (v).end()

const int mod = 1000000000 + 7;
const ll inf = 1e16;

void solve() {
  int n, m;
  cin >> n >> m;

  int u, v, w;

  vector<vector<pair<int, int>>> g(n + 1);

  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }

  vector<vector<ll>> dist(n + 1, vector<ll>(2, inf));

  dist[1][0] = 0;
  dist[1][1] = 0;

  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push({0, 1, 0});

  while (!pq.empty()) {
    auto [cost, node, useCoupon] = pq.top();
    pq.pop();

    if (dist[node][useCoupon] < cost) {
      continue;
    }

    for (auto [nb, nbw] : g[node]) {
      z

          if (useCoupon == 1) {

        if (cost + nbw < dist[nb][1]) {
          dist[nb][1] = cost + nbw;
          pq.push({cost + nbw, nb, 1});
        }
      }
      else {
        if (cost + nbw < dist[nb][0]) {
          dist[nb][0] = cost + nbw;
          pq.push({cost + nbw, nb, 0});
        }

        // halve the price
        int half_price = nbw / 2;
        if (cost + half_price < dist[nb][1]) {
          dist[nb][1] = cost + half_price;
          pq.push({cost + half_price, nb, 1});
        }
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= 1; j++) {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << min(dist[n][0], dist[n][1]) << "\n";
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
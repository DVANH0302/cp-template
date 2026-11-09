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

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n), c(n);
  vector<pair<ll, int>> v;
  rep(i, 0, n) {
    cin >> a[i] >> b[i] >> c[i];
    v.push_back({a[i] + b[i] + c[i], i});
  }
  sort(all(v));
  auto cost = [&](int j) -> ll {
    if (a[j] == b[j] && b[j] == c[j])
      return -1;
    if (a[j] <= b[j] && b[j] <= c[j]) {
      ll e = b[j] - a[j] + 1;
      if (a[j] < b[j])
        e = min(e, c[j] - b[j] + 1);
      return 2 * e;
    }
    return 0;
  };
  ll S = v[0].first;
  rep(i, 0, n) {
    ll p = cost(v[i].second);
    if (p < 0 || (k -= p) < 0) {
      cout << S << "\n";
      return;
    }
    if (i + 1 == n) {
      cout << S + k / n << "\n";
      return;
    }
    ll gap = (v[i + 1].first - S) * (i + 1);
    if (gap > k) {
      cout << S + k / (i + 1) << "\n";
      return;
    }
    k -= gap;
    S = v[i + 1].first;
  }
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
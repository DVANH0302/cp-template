#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  ll n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  cout << abs(min({x1 - 1, n - x1, y1 - 1, n - y1}) -
              min({x2 - 1, n - x2, y2 - 1, n - y2}))
       << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
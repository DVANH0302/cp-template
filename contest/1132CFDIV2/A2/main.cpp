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
  int n;
  cin >> n;
  vector<ll> a(n);
  trav(ai, a) {
    int v;
    cin >> v;
    ai = 1LL << v;
  }
  sort(a.rbegin(), a.rend());

  ll x = 0, y = 0;
  for (ll v : a) {
    if (x <= y)
      x += v;
    else
      y += v;
  }

  cout << x * y << "\n";
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
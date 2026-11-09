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
  trav(ai, a) { cin >> ai; };

  sort(all(a));

  ll curMax = a[0];
  ll delta = 0;
  for (int i = 1; i < n; i++) {

    delta -= a[i - 1];

    a[i] = a[i] + delta;

    curMax = max(curMax, a[i]);
  }

  cout << curMax << "\n";
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
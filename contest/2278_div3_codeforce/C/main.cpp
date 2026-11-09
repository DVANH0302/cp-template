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
  vector<int> a(n);
  trav(ai, a) cin >> ai;

  bool has_first = false;
  bool has_middle = false;
  bool has_end = false;

  for (int i = 0; i < n; i++) {
    if (a[i] > 1) {
      if (i == 0) {
        has_first = true;
      } else if (i == n - 1) {
        has_end = true;
      } else {
        has_middle = true;
      }
    }
  }

  ll res;
  if (has_middle) {
    res = accumulate(all(a), 0LL) - 1;
  } else if (has_first && has_end) {
    res = (ll)(a[0] + a[n - 1] - 1);
  } else if (has_first || has_end) {
    res = a[0] > 1 ? (ll)a[0] : (ll)a[n - 1];
  } else {
    res = -1;
  }
  cout << res << "\n";
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
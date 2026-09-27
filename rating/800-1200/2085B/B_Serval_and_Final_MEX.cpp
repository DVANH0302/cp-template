#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

#define pb push_back

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<pair<int, int>> res;
  int step = 0;
  if (n >= 5) {
    bool hasZero = false;
    step++;
    for (int i = 3; i < n; i++) {
      if (a[i] == 0) {
        hasZero = true;
        break;
      }
    }
    if (!hasZero) {
      a[3] = 0;
    } else {
      a[3] = 1;
    }
    res.pb({4, n});
  }

  int nr = 4;
  if (a[2] == 0 || a[3] == 0) {
    res.pb({3, 4});
    nr--;
    step++;
  }

  if (a[0] == 0 || a[1] == 0) {
    res.pb({1, 2});
    nr--;
    step++;
  }

  res.pb({1, nr});
  step++;
  cout << step << '\n';
  for (auto [l, r] : res) {
    cout << l << " " << r << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)

    solve();
}
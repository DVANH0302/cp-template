#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  if (n - 2 < k) {
    cout << -1 << '\n';
    return;
  }
  int c0, c1;
  c1 = n / 2;
  c0 = n - c1;

  int d = n - 2 - k;
  string res;
  for (int i = 0; i < d / 2; i++) {
    res += "01";
    c1--;
    c0--;
  }
  if (d % 2 == 1) {
    res += '0';
    c0--;
    while (c1--) {
      res += '1';
    }
    while (c0--) {
      res += '0';
    }
  } else {
    while (c0--) {
      res += '0';
    }
    while (c1--) {
      res += '1';
    }
  }

  cout << res << '\n';
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
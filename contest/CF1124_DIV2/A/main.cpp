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
  ll res;
  if (n == k) {
    res = 2 * n;
  } else {
    res = pow(2, (n - k + 1)) + 2 * (k - 1);
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
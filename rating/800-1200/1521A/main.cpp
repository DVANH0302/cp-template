#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  ll A, B;
  cin >> A >> B;
  if (B == 1) {
    cout << "NO\n";
    return;
  }
  ll x, y, z;
  x = (B + 1) * A;
  y = (3 * B - 1) * A;
  z = 4 * A * B;

  cout << "YES" << "\n";
  cout << x << " " << y << " " << z << "\n";
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
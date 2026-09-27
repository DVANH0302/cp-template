#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  ll n, a, b;
  string s;

  cin >> n >> a >> b;
  cin >> s;

  if (b >= 0) {
    cout << n * (a + b) << "\n";
    return;
  }

  ll c0 = 0;
  ll c1 = 0;

  int i = 0;
  while (i < n) {
    if (s[i] == '0') {
      c0++;
      while (i < n && s[i] == '0') {
        i++;
      }
    } else if (s[i] == '1') {
      c1++;
      while (i < n && s[i] == '1') {
        i++;
      }
    }
  }

  // dbg((min(c0, c1) + 1) * b);

  ll res = n * a + (min(c0, c1) + 1) * b;

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
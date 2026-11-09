#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  vector<ll> b(n + 1, 0);
  for (ll i = 1; i < n + 1; i++) {
    cin >> b[i];
  }
  vector<ll> a(n + 1, 0);

  ll nnum = 1;

  a[1] = nnum;
  nnum++;

  for (ll i = 2; i < n + 1; i++) {
    ll x = b[i] - b[i - 1];
    if (i - x == 0) {
      a[i] = nnum;
      nnum++;
    } else {
      a[i] = a[i - x];
    }
  }

  for (ll i = 1; i < n + 1; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;
  while (t--)

    solve();
}
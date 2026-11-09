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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  trav(ai, a) cin >> ai;

  vector<int> rk(k, 0);

  vector<ll> prefix(n, 0);

  prefix[0] = a[0];

  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  ll count = 0;
  for (int i = k; i < n; i++) {
    if (prefix[i] % k == 0) {
      count++;
    }
  }

  for (int i = n - 1; i >= k + 1; i--) {
    rk[prefix[i] % k]++;

    count += rk[prefix[i - k - 1] % k];
  }

  cout << count << "\n";
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
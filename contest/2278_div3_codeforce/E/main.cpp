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

  ll S = accumulate(all(a), 0LL);

  for (int i = 0; i < n - 1; i++) {
    ll newS = S - 2 * (a[i] + a[i + 1]);
    if (newS > S) {
      S = newS;
      int nai = -a[i + 1];
      int nai1 = -a[i];
      a[i] = nai;
      a[i + 1] = nai1;
    }
  }

  cout << S << "\n";
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
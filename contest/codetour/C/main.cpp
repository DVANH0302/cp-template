#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  ll n, S, D;
  ll res = 0;

  cin >> n >> S >> D;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  multiset<int> ms;

  for (int i = 0; i < n; i++) {
    while (!ms.empty() && a[i] - *ms.begin() > D) {
      ms.erase(ms.begin());
    }

    auto it = ms.lower_bound(S - a[i]);
    if (it != ms.end()) {
      res++;
      ms.erase(it);
    } else {
      ms.insert(a[i]);
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // int t;
  // cin >> t;
  // while (t--)

  solve();
}
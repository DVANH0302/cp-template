#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  ll sum = accumulate(a.begin(), a.end(), 0);
  set<ll> s;
  for (int i = 0; i < n; i++) {
    s.insert(a[i] - i);
  }

  int best = 0, cur = 0;
  for (auto x : s) {
    if (s.find(x - 1) != s.end())
      cur++;
    else {
      cur = 1;
    }
    best = max(best, cur);
  }
  cout << best << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
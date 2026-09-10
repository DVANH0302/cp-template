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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  dbg(a);

  cout << n << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;
using ull = unsigned long long;
void solve() {
  int n;
  ull k;
  cin >> n >> k;
  vector<ull> a(n);
  for (auto &x : a)
    cin >> x;

  ull res = 0;
  vector<ull> p;
  for (auto x : a) {
    for (int i = 0; i < 64; i++) {
      if ((x & (1ULL << i)) == 0) {
        p.push_back(i);
      } else {
        res += 1;
      }
    }
  }
  sort(p.begin(), p.end());

  int i = 0;

  while (k >= (1ULL << p[i])) {
    k -= 1ULL << p[i];
    res += 1;
    i++;
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)

    solve();
}
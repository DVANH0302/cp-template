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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  trav(x, a) cin >> x;
  vector<int> v(n - 4, 0);

  ll count = 0;
  unordered_map<int, int> map;

  for (int x = 0; x < n - 4; x++) {
    v[x] = a[x] + a[x + 2] - a[x + 4];
  }

  for (int x = n - 5; x >= 0; x--) {

    if (map.find(v[x]) == map.end()) {
      map[v[x]] = 1;
      continue;
    }

    count += map[v[x]];

    if (x + 2 < n - 4 && v[x + 2] == v[x]) {
      count--;
    }
    if (x + 4 < n - 4 && v[x + 4] == v[x]) {
      count--;
    }

    map[v[x]]++;
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
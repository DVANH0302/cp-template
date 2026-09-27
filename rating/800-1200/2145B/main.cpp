#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  vector<int> f(n + 1, 1);
  int c2 = 0;
  int l = 1, r = n;

  for (auto x : s) {
    // cout << x << '\n';
    if (x == '0') {
      f[l] = 0;
      l++;
    } else if (x == '1') {
      f[r] = 0;
      r--;
    } else if (x == '2') {
      c2 += 1;
    }
  }

  if (l + c2 - 1 >= r) {
    for (int i = l; i <= r; i++) {
      f[i] = 0;
    }
  } else {
    while (l <= r && c2--) {
      f[l] = 2;
      f[r] = 2;
      l++;
      r--;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (f[i] == 0)
      cout << '-';
    else if (f[i] == 1)
      cout << '+';
    else if (f[i] == 2)
      cout << '?';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)

    solve();
}
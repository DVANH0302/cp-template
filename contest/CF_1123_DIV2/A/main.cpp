#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n;
  char c;
  string s;
  cin >> n >> c;
  cin >> s;

  int l = 0, r = n - 1;
  int res = 0;
  while (l < r) {
    if (s[l] != s[r]) {
      res += 2;
      if (s[l] == c || s[r] == c)
        res--;
    }
    l++;
    r--;
  }
  cout << res << '\n';
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
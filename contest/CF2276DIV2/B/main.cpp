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
  string s;
  cin >> s;

  int n = (int)s.size();

  bool add = false;
  bool minus = false;
  int count = 1;
  for (int i = 1; i < n - 1; i++) {
    if (s[i - 1] == s[i + 1]) {
      if (s[i] != s[i - 1]) {
        minus = true;
      } else {
        add = true;
      }
    }
  }
  if (minus) {
    count++;
  }
  if (add) {
    count++;
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
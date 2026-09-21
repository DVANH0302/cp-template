#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void solve() {
  string s;
  cin >> s;
  int l = 0, r = 0;
  int best = 0;
  for (int r = 0; r < (int)s.size(); r++) {
    if (s[r] == s[l]) {
      best = max(best, r - l + 1);
    } else {
      l = r;
    }
  }
  cout << best << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
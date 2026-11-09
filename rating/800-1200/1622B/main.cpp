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
  vector<int> p(n);
  trav(pi, p) cin >> pi;
  string s;
  cin >> s;

  vector<int> res(n);
  vector<pair<int, int>> ls1, ls0;

  rep(i, 0, n) {
    if (s[i] == '1') {
      ls1.push_back({p[i], i});
    } else {
      ls0.push_back({p[i], i});
    }
  }

  sort(all(ls0));
  sort(all(ls1));
  int n1 = (int)ls1.size();
  int n0 = (int)ls0.size();

  rep(i, 0, n0) { res[ls0[i].second] = i + 1; }

  int j = n0 + 1;
  rep(i, 0, n1) {
    res[ls1[i].second] = j;
    j++;
  }

  for (auto x : res) {
    cout << x << " ";
  }
  cout << "\n";
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
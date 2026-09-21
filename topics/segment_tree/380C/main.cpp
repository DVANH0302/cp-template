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

void build(int node, int tl, int tr, vector<vector<int>> &t, string &s) {
  if (tl == tr) {
    if (s[tl] == '(') {
      t[node][1] += 1;
    } else {
      t[node][2] += 1;
    }
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(2 * node, tl, tm, t, s);
  build(2 * node + 1, tm + 1, tr, t, s);

  int lv = t[2 * node][0], lo = t[2 * node][1], lc = t[2 * node][2];
  int rv = t[2 * node + 1][0], ro = t[2 * node + 1][1], rc = t[2 * node + 1][2];

  int av = min(lo, rc);

  t[node][0] = lv + rv + av;
  t[node][1] = lo + ro - av;
  t[node][2] = lc + rc - av;
}

vector<int> query(int node, int tl, int tr, int l, int r,
                  vector<vector<int>> &t) {
  if (tl > r || tr < l) {
    return vector<int>(3, 0);
  }

  if (tl == tr) {
    return t[node];
  }
  int tm = tl + (tr - tl) / 2;
  vector<int> lq = query(2 * node, tl, tm, l, r, t);
  vector<int> rq = query(2 * node + 1, tm + 1, tr, l, r, t);

  int lv = lq[0], lo = lq[1], lc = lq[2];
  int rv = rq[0], ro = rq[1], rc = rq[2];

  int av = min(lo, rc);
  vector<int> cq = vector<int>(3, 0);
  cq[0] = lv + rv + av;
  cq[1] = lo + ro - av;
  cq[2] = lc + rc - av;

  return cq;
}

void solve() {
  string s;
  cin >> s;

  int n = sz(s);
  vector<vector<int>> t =
      vector<vector<int>>(4 * n, vector<int>(3, 0)); // (num valid, open,
      close)
  // int valid_[4 * n], open_[4 * n], close_[4 * n];

  int m;
      cin >> m;

      build(1, 0, n - 1, t, s);

      int l, r;
      for (int i = 0; i < m; i++) {
        cin >> l >> r;
        l -= 1;
        r -= 1;
        cout << query(1, 0, n - 1, l, r, t)[0] * 2 << endl;
      }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
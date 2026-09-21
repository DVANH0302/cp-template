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

void build(vector<vector<int>> &t, vector<int> &arr, int node, int l, int r) {
  if (l == r) {
    t[node].pb(arr[l]);
    return;
  }
  int mid = l + (r - l) / 2;
  build(t, arr, node * 2, l, mid);
  build(t, arr, node * 2 + 1, mid + 1, r);

  auto &c1 = t[2 * node];
  auto &c2 = t[2 * node + 1];
  int i1 = 0;
  int i2 = 0;

  while (i1 < sz(c1) and i2 < sz(c2)) {
    if (c1[i1] < c2[i2]) {
      t[node].pb(c1[i1]);
      i1 += 1;
    } else {
      t[node].pb(c2[i2]);
      i2 += 1;
    }
  }

  while (i1 < sz(c1)) {
    t[node].pb(c1[i1]);
    i1 += 1;
  }

  while (i2 < sz(c2)) {
    t[node].pb((c2[i2]));
    i2 += 1;
  }
}

int query(vector<vector<int>> &t, int node, int tl, int tr, int l, int r,
          int k) {
  if (tl > r || tr < l)
    return 0;

  if (l <= tl && tr <= r) {
    auto it = upper_bound(t[node].begin(), t[node].end(), k);
    return t[node].end() - it;
  }

  int tm = (tl) + (tr - tl) / 2;
  return query(t, 2 * node, tl, tm, l, r, k) +
         query(t, 2 * node + 1, tm + 1, tr, l, r, k);
}

void solve() {
  int n, q;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;

  cin >> q;
  vector<vector<int>> t(4 * n, vector<int>());
  int i, j, k;
  build(t, arr, 1, 0, n - 1);

  for (int x = 0; x < q; x++) {
    cin >> i >> j >> k;
    int r = query(t, 1, 0, n - 1, i - 1, j - 1, k);
    cout << r << "\n";
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
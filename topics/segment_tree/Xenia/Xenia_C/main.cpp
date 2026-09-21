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

void build(int node, int tl, int tr, vector<int> &t, vector<int> &arr) {
  if (tl == tr) {
    t[node] = arr[tl];
    return;
  }

  int tm = tl + (tr - tl) / 2;

  build(2 * node, tl, tm, t, arr);
  build(2 * node + 1, tm + 1, tr, t, arr);

  int n = (int)log2(tr - tl + 1);
  if (n % 2 == 0) {
    t[node] = t[2 * node] ^ t[2 * node + 1];
  } else {
    t[node] = t[2 * node] | t[2 * node + 1];
  }
}

void update(int node, int tl, int tr, vector<int> &t, int p, int b) {
  if (tl > p || tr < p)
    return;

  if (tl == tr) {
    t[node] = b;
    return;
  }
  int tm = tl + (tr - tl) / 2;
  update(2 * node, tl, tm, t, p, b);
  update(2 * node + 1, tm + 1, tr, t, p, b);

  int n = (int)log2(tr - tl + 1);
  // printf("tl: %d, tr: %d, node %d, l: %d, r: %d\n", tl, tr, t[node],
  //        t[2 * node], t[2 * node + 1]);
  if (n % 2 == 0) {
    t[node] = t[2 * node] ^ t[2 * node + 1];
  } else {
    t[node] = t[2 * node] | t[2 * node + 1];
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  int N = (int)pow(2, n);

  vector<int> arr(N);
  vector<vector<int>> queries(m, vector<int>(2));
  vector<int> t(4 * N);
  for (auto &x : arr)
    cin >> x;

  build(1, 0, N - 1, t, arr);
  int p, b;
  // use p-1 (0 based index)
  for (int i = 0; i < m; i++) {
    cin >> p >> b;
    update(1, 0, N - 1, t, p - 1, b);
    // dbg(t);
    cout << t[1] << "\n";
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
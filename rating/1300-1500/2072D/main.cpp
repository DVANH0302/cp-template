#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

// void build(int node, int tl, int tr, vector<pair<int, int>> &t,
//            vector<int> &a) {
//   if (tl == tr) {
//     t[node] = {a[tl], a[tl]};
//     return;
//   }
//   int tm = (tl + tr) / 2;
//   build(2 * node, tl, tm, t, a);
//   build(2 * node + 1, tm + 1, tr, t, a);

//   t[node] = {min(t[2 * node].first, t[2 * node + 1].first),
//              max(t[2 * node].second, t[2 * node + 1].second)};
// }

// int qmin(int node, int tl, int tr, int l, int r, int target,
//          vector<pair<int, int>> &t) {
//   if (tl > r || tr < l) {
//     return 0;
//   }

//   if (tl == tr) {
//     return t[node].first > target ? 1 : 0;
//   }

//   int tm = (tl + tr) / 2;

//   int cmin = t[node].first, cmax = t[node].second;

//   if (l <= tl && tr <= r) {
//     if (cmin > target) {
//       return tr - tl + 1;
//     } else if (cmax < target) {
//       return 0;
//     }
//   }
//   return qmin(2 * node, tl, tm, l, r, target, t) +
//          qmin(2 * node + 1, tm + 1, tr, l, r, target, t);
// }

// int qmax(int node, int tl, int tr, int l, int r, int target,
//          vector<pair<int, int>> &t) {
//   if (tl > r || tr < l) {
//     return 0;
//   }

//   if (tl == tr) {
//     return t[node].first < target ? 1 : 0;
//   }

//   int tm = (tl + tr) / 2;

//   int cmin = t[node].first, cmax = t[node].second;

//   if (l <= tl && tr <= r) {
//     if (cmax < target) {
//       return tr - tl + 1;
//     } else if (cmin > target) {
//       return 0;
//     }
//   }
//   return qmax(2 * node, tl, tm, l, r, target, t) +
//          qmax(2 * node + 1, tm + 1, tr, l, r, target, t);
// }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int total = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[i]) {
        total++;
      }
    }
  }

  // vector<pair<int, int>> t(4 * n, {0, 0});
  // build(1, 0, n - 1, t, a);

  int best = total;
  int bl = 0, br = 0;

  for (int i = 0; i < n; i++) {
    int delta = 0;
    for (int j = i + 1; j < n; j++) {
      if (a[j] > a[i])
        delta++;
      else if (a[j] < a[i])
        delta--;

      if (total + delta < best) {
        best = total + delta;
        bl = i;
        br = j;
      }
    }
  }

  cout << bl + 1 << " " << br + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)

    solve();
}
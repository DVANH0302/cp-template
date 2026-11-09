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

struct DSU {
  vector<int> parents;
  DSU(int n) : parents(n + 1) { iota(parents.begin(), parents.end(), 0); }

  int find(int a) {
    while (parents[a] != a) {
      parents[a] = parents[parents[a]];
      a = parents[a];
    }
    return a;
  }

  void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb) {
      parents[pb] = pa;
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);

  int c1, c2;
  for (int i = 0; i < m; i++) {
    cin >> c1 >> c2;
    dsu.unite(c1, c2);
  }

  set<int> reps;

  for (int i = 1; i < n + 1; i++) {
    reps.insert(dsu.find(i));
  }

  if (reps.size() <= 1) {
    cout << 0 << "\n";
    return;
  }

  cout << reps.size() - 1 << "\n";

  for (auto it = reps.begin(); it != reps.end(); it++) {
    if (it == reps.begin())
      continue;
    cout << *reps.begin() << " " << *it << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // int t;
  // cin >> t;
  // while (t--)

  solve();
}
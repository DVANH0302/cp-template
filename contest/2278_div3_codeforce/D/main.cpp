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
  vector<int> a(n);

  trav(ai, a) cin >> ai;

  sort(all(a));

  ll cost = 0;
  ll ops = 0;

  for (int i = 0; i < n - 1; i++) {

    ll d = a[i + 1] - a[i];
    // lock first i, reduce unlock until equal first ith nums
    ll c1 = (i + 1) * d;

    // lock from [i+1 .. n-1], increase unlock until equal a[i+1]
    ll c2 = (n - (i + 1)) * d;

    cost += min(c1, c2);
    ops += d;
  }

  cout << cost << " " << ops << "\n";
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
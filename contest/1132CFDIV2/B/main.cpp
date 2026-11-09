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

const string yes = "YES\n";
const string no = "NO\n";

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  trav(ai, a) cin >> ai;
  sort(a.rbegin(), a.rend());

  if (k < n && a[0] == a[k]) {
    cout << no;
    return;
  }
  cout << yes;
  for (int i = k - 1; i >= 0; i--)
    cout << a[i] << " ";
  for (int i = k; i < n; i++)
    cout << a[i] << " ";
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
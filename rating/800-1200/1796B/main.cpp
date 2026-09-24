#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  string a, b;
  int m, n;
  cin >> a;
  cin >> b;
  m = (int)a.size();
  n = (int)b.size();

  if (a[0] == b[0]) {
    cout << "YES\n";
    cout << a[0] << '*' << "\n";
    return;
  }
  if (a[m - 1] == b[n - 1]) {
    cout << "YES\n";
    cout << '*' << a[m - 1] << "\n";
    return;
  }
  set<string> sa;

  for (int i = 0; i < m - 1; i++) {
    sa.insert(a.substr(i, 2));
  }

  for (int i = 0; i < n - 1; i++) {
    string cur = b.substr(i, 2);
    if (sa.count(cur)) {
      cout << "YES\n";
      cout << "*" << cur << "*\n";
      return;
    }
  }

  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
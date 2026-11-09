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

bool isValid(int n) {
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      return true;
    }
  }
  return false;
}
void solve() {
  int n;
  cin >> n;

  if (n % 2 == 0 && isValid(n / 2)) {
    cout << "YES" << "\n";
    return;
  }
  if (n % 4 == 0 && isValid(n / 4)) {
    cout << "YES" << "\n";
    return;
  }

  cout << "NO" << "\n";
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
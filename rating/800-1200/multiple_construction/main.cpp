#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;

  for (int i = n; i > 0; i--) {
    cout << i << " ";
  }
  cout << n << " ";
  for (int i = 1; i < n; i++) {
    cout << i << " ";
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
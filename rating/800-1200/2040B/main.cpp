#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;
int n;
void solve() {
  cin >> n;

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  if (n < 5) {
    cout << 2 << "\n";
    return;
  }

  int res = 2;
  int x = 1;
  int target = (int)ceil(((double)n) / 2);
  while (x < target - 1) {
    x = (x + 1) * 2;
    res++;
  }
  cout << res << "\n";
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
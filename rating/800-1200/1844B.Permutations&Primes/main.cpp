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
  int n;
  cin >> n;
  int m = n / 2;
  vector<int> arr = vector<int>(n, 0);

  arr[0] = 2;
  arr[n - 1] = 3;
  arr[m] = 1;

  int c = 4;

  for (auto &x : arr) {
    if (x == 0) {
      x = c++;
    }
  }

  for (auto x : arr) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
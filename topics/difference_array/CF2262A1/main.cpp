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
  vector<int> a = vector<int>(n);

  for (auto &x : a) {
    cin >> x;
  }

  vector<int> diff = vector<int>(n + 2, 0);

  for (int i = 0; i < n; i++) {

    int idx = i + 1;
    int l = min(idx * a[i], n + 1);
    int r = min(idx * (a[i] + 1), n + 1);

    diff[l] += 1;
    diff[r] -= 1;
  }

  int cnt = diff[0] == 0 ? 1 : 0;
  for (int i = 1; i < n; i++) {
    diff[i] += diff[i - 1];
    if (diff[i] == 0)
      cnt++;
  }
  cout << cnt << "\n";
  for (int i = 0; i < n; i++) {
    if (diff[i] == 0) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
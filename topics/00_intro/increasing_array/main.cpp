#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (auto &x : arr) {
    cin >> x;
  }

  ll res = 0;
  for (ll i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      res += arr[i - 1] - arr[i];
      arr[i] = arr[i - 1];
    }
  }
  cout << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
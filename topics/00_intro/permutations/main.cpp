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
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  if (n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
    return;
  }

  ll so, se;
  if (n % 2 == 0) {
    se = n;
    so = n - 1;
  } else {
    so = n;
    se = n - 1;
  }

  for (ll i = so; i >= 1; i = i - 2) {
    cout << i << " ";
  }
  for (ll i = se; i >= 1; i = i - 2) {
    if (i == 2) {
      cout << i << endl;
      return;
    }

    cout << i << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define f first
#define s second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n - 1);
  for (auto &x : a)
    cin >> x;

  ll missing = (ll)((n * (n + 1)) / 2 - accumulate(a.begin(), a.end(), 0LL));
  cout << missing << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
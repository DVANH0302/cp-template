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
  int n;
  cin >> n;
  vector<int> le;
  vector<int> ge;
  char exp;
  int val;
  int res = 0;
  for (int i = 0; i < n; i++) {

    cin >> exp >> val;
    if (exp == 'L') {
      le.pb(val);
    } else {
      ge.pb(val);
    }
  }

  sort(le.begin(), le.end());
  for (int i = 0; i < le.size(); i++) {
    int l = le[i];
    int count = 0;
    for (auto r : ge) {
      if (l >= r)
        count++;
    }
    res = max(res, count + (int)le.size() - i);
  }

  cout << n - res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
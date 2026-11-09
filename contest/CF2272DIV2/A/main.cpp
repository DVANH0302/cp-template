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

void display(vector<int> &a) {
  trav(ai, a) cout << ai << " ";
  cout << "\n";
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);

  trav(ai, a) cin >> ai;
  int mex = -1;
  set<int> s;

  for (int i = 0; i <= n - k; i++) {
    s.insert(a[i]);
  }

  for (int i = 0; i < n; i++) {
    if (s.find(i) == s.end()) {
      mex = i;
      break;
    }
  }

  if (mex == -1) {
    cout << -1 << "\n";
    return;
  }

  int maxi = *max_element(s.begin(), s.end());
  int l1, l2;
  for (int i = 0; i < n; i++) {
    if (a[i] == maxi) {
      l1 = i + 1;
    } else if (a[i] == mex) {
      l2 = i + 1;
    }
  }

  cout << l1 << " " << l2 << "\n";
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
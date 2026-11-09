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

string yes = "YES\n";
string no = "NO\n";

void solve() {
  int n, m;
  cin >> n >> m;
  string p, q;
  cin >> p >> q;

  char a = 'a';
  vector<int> count_p(26, 0);

  for (char cp : p) {
    count_p[cp - a] += 1;
  }

  for (char cq : q) {
    count_p[cq - a] -= 1;

    if (count_p[cq - a] < 0) {
      cout << no;
      return;
    }
  }

  char s = 's' - a;
  char i = 'i' - a;
  char x = 'x' - a;

  for (int idx = 0; idx < 26; idx++) {
    if (idx == s || idx == i || idx == x) {
      if (count_p[idx] != 1) {
        cout << no;
        return;
      }
    } else {
      if (count_p[idx] != 0) {
        cout << no;
        return;
      }
    }
  }

  cout << yes;
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
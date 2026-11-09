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

char r = 'R';
char s = 'S';
char p = 'P';

void display(char c, int n) {
  rep(i, 0, n) { cout << c; }
  cout << "\n";
}
void solve() {
  int x, y, z;
  cin >> x >> y >> z;

  int total = x + y + z;
  if (y >= ceil((double)(y + z) / 2)) {
    display(r, total);
    return;
  } else if (x >= ceil((double)(x + y) / 2)) {
    display(p, total);
    return;
  } else {
    display(s, total);
    return;
  }
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
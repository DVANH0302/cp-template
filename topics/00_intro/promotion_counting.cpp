#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int b[2], s[2], g[2], p[2];

  int bs = 0;
  int sg = 0;
  int gp = 0;

  cin >> b[0] >> b[1];bo
  cin >> s[0] >> s[1];
  cin >> g[0] >> g[1];
  cin >> p[0] >> p[1];

  int pi = p[1] - p[0];
  gp += pi;
  sg += pi;
  bs += pi;

  int gi = g[1] - g[0];
  sg += gi;
  bs += gi;

  int si = s[1] - s[0];
  bs += si;

  cout << bs << endl << sg << endl << gp << endl;
}
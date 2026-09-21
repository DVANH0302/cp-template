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

int dfs(int n, int src, int aux, int end, stringstream &out) {
  if (n == 0) {
    return 0;
  }
  int res = 1;
  res += dfs(n - 1, src, end, aux, out);
  out << src << " " << end << "\n";
  res += dfs(n - 1, aux, src, end, out);
  return res;
}

void solve() {
  int n;
  cin >> n;
  stringstream out;
  int res = dfs(n, 1, 2, 3, out);
  string out_str = out.str();
  out_str = to_string(res) + '\n' + out.str();
  cout << out_str;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
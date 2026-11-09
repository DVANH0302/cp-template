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

string yes = "yes\n";
string no = "no\n";

void display(vector<int> &ls) {
  trav(num, ls) { cout << num << " "; }
  cout << "\n";
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  trav(ai, a) cin >> ai;
  vector<int> p(n), q(n);

  vector<int> visited(n + 1, 0);
  vector<pair<int, int>> sorted_a;

  rep(i, 0, n) { sorted_a.push_back({a[i], i}); }
  sort(sorted_a.begin(), sorted_a.end());

  int cur_min = 1;
  rep(i, 0, n) {
    auto [v, idx] = sorted_a[i];

    if (i + 1 > v) {
      cout << no;
      return;
    }
    q[idx] = i + 1;

    if (i + 1 < v) {

      p[idx] = v;
      visited[v] = 1;
    } else {
      while (visited[cur_min] == 1) {
        cur_min++;
      }
      p[idx] = cur_min;
      visited[cur_min] = 1;
    }
  }
  cout << yes;
  display(p);
  display(q);
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
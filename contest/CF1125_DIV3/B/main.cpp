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

void solve() {
  int n;
  cin >> n;
  string cs;
  cin >> cs;

  vector<int> visit(n + 1, 0);
  stack<int> stack;

  for (int i = 1; i < n + 1; i++) {
    if (cs[i - 1] == '1') {
      stack.push(i);
    } else if (cs[i - 1] == '2') {
      if (!stack.empty()) {
        visit[stack.top()] = 1;
        stack.pop();
      } else {
        visit[i] = 1;
      }
    } else {
      visit[i] = 1;
    }
  }

  int k = 0;
  rep(i, 1, n + 1) {
    if (visit[i] == 0) {
      k++;
    }
  }
  cout << k << "\n";
  rep(i, 1, n + 1) {
    if (visit[i] == 0) {
      cout << i << " ";
    }
  }
  cout << "\n";
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
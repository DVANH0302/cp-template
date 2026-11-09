#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

void solve() {
  int n;
  int best = 0;

  cin >> n;
  vector<int> h(n);
  vector<vector<int>> g = vector<vector<int>>(n, vector<int>());
  vector<int> d = vector<int>(n, 0);
  stack<int> st;
  for (auto &x : h) {
    cin >> x;
  }

  for (int i = 0; i < n; i++) {
    while (!st.empty() && h[i] > h[st.top()]) {
      g[i].push_back(st.top());
      d[st.top()]++;
      st.pop();
    }
    if (!st.empty() && h[st.top()] > h[i]) {
      g[st.top()].push_back(i);
      d[i]++;
    }
    st.push(i);
  }

  deque<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      q.push_back({i, 1});
    }
  }
  while (!q.empty()) {
    auto item = q.front();
    q.pop_front();

    int node = item.first, cost = item.second;
    best = max(best, cost);
    for (auto nb : g[node]) {
      d[nb]--;
      if (d[nb] == 0) {
        q.push_back({nb, cost + 1});
      }
    }
  }

  cout << best << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // int t;
  // cin >> t;
  // while (t--)

  solve();
}
#include <bits/stdc++.h>
using namespace std;

// #include "debug.h"

#if !defined(ONLINE_JUDGE) || defined(LOCAL)
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

// for (auto &x : arr) {
//   cout << x << " ";
// }

void solve() {
  int n;
  cin >> n;
  vector<int> a = vector<int>(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<pair<int, int>> intervals = vector<pair<int, int>>();

  for (int i = 0; i < n; i++) {
    int idx = i + 1;
    intervals.push_back({a[i] * idx, (a[i] + 1) * idx - 1});
  }
  sort(intervals.begin(), intervals.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
  vector<pair<int, int>> cis = vector<pair<int, int>>();

  cis.push_back(intervals[0]);
  for (int i = 1; i < n; i++) {
    if (intervals[i].first <= cis.back().second) {
      cis.back().second = max(intervals[i].second, cis.back().second);
    } else {
      cis.push_back(intervals[i]);
    }
  }
  vector<int> freq = vector<int>(n, 1);
  int rm = 0;
  for (auto &item : cis) {
    if (item.first >= n)
      continue;
    for (int i = item.first; i <= min(item.second, n - 1); i++) {
      freq[i] = 0;
      rm++;
    }
  }
  cout << n - rm << "\n";
  for (int i = 0; i < n; i++) {
    if (freq[i] == 1) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
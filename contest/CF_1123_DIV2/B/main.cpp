#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL)
#include "debug.h"
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int, greater<int>> counter;
  for (auto &x : a) {
    cin >> x;
    counter[x]++;
  }

  while (!counter.empty()) {
    for (auto it = counter.begin(); it != counter.end();) {
      cout << it->first << " ";
      it->second--;
      if (it->second == 0) {
        it = counter.erase(it);
      } else {
        it++;
      }
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
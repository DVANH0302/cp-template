

#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

vector<int> find_divisor(int x) {
  vector<int> ls;
  for (int i = 2; (ll)i * i <= x; i++) {
    if (x % i == 0) {
      ls.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }

  if (x > 1) {
    ls.push_back(x);
  }

  return ls;
}

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  vector<int> divs = find_divisor(x);
  int ndiv = (int)divs.size();

  vector<ll> scores(ndiv, 0);

  for (auto &num : a) {
    cin >> num;
  }

  if (ndiv == 0) {
    cout << 0 << "\n";
    return;
  }
  for (auto num : a) {
    for (int i = 0; i < ndiv; i++) {
      if (num % divs[i] == 0) {
        scores[i] += num;
      }
    }
  }
  // dbg(divs);
  // dbg(scores);
  cout << *max_element(scores.begin(), scores.end()) << "\n";
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
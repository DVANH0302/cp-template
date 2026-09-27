#include <bits/stdc++.h>
using namespace std;

#if defined(LOCAL) || defined(CPH)
#include "debug.h"
#else
#define dbg(x)
#endif

using ll = long long;

string subtract(string a, string b) {
  vector<int> res;
  int m = (int)a.size();
  int n = (int)b.size();

  int i = m - 1;
  int j = n - 1;
  int carry = 0;
  while (i > -1 && j > -1) {
    
  }
}

void solve() {
  ll n;
  string x;
  cin >> n;
  cin >> x;

  string a = "1";
  for (int i = 0; i < n - 1; i++) {
    a += '0';
  }
  a += '1';

  string b;
  for (int i = 0; i < n + 1; i++) {
    b += '1';
  }

  dbg(a);
  dbg(b);
  // dbg(x);
  // dbg(a);
  // dbg(b);
  // dbg(a - x);
  // dbg(b - x);
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
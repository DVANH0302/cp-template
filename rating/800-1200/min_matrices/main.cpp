#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void display(vector<vector<int>> &A, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  if (k < n || k > 2 * n - 1) {
    cout << -1 << '\n';
    return;
  }
  vector<vector<int>> A = vector<vector<int>>(n, vector<int>(n, 0));
  int c = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = c;
      c += 1;
    }
  }

  int moved = 2 * n - 1 - k;

  for (int i = 1; i <= moved; i++) {
    int temp = A[0][i];
    A[0][i] = A[i][i];
    A[i][i] = temp;
  }

  display(A, n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
#include <bits/stdc++.h>
using namespace std;

// ============================================================================
//  Random helpers  (Python equivalents in comments)
// ============================================================================

// Seeded with the clock so every run is different.
// Replace the argument with a fixed number (e.g. 42) to get the same
// sequence every time — useful when reproducing a failure.
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// random.randint(l, r)  — integer in [l, r], inclusive both ends
long long rnd(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}

// random.random()  — double in [0, 1)
double rnd01() { return uniform_real_distribution<double>(0.0, 1.0)(rng); }

// random.choice(v)  — one element from a vector
template <typename T> T choice(const vector<T> &v) {
  return v[rnd(0, (long long)v.size() - 1)];
}

// random.choice("abc")  — one character from a string
char choice(const string &s) { return s[rnd(0, (long long)s.size() - 1)]; }

// random.shuffle(v)  — shuffle in place
template <typename T> void shuffle_vec(vector<T> &v) {
  shuffle(v.begin(), v.end(), rng);
}

// [random.randint(l, r) for _ in range(n)]  — array of n ints in [l, r]
vector<long long> rnd_array(int n, long long l, long long r) {
  vector<long long> a(n);
  for (auto &x : a)
    x = rnd(l, r);
  return a;
}

// random.sample(range(1, n + 1), n)  — permutation of 1..n
vector<int> rnd_perm(int n) {
  vector<int> p(n);
  iota(p.begin(), p.end(), 1); // 1, 2, ..., n
  shuffle_vec(p);
  return p;
}

// random string of length n from the given alphabet
string rnd_string(int n, const string &alphabet = "abc") {
  string s;
  for (int i = 0; i < n; i++)
    s += choice(alphabet);
  return s;
}

// random tree on n nodes, returned as list of edges (u, v), 1-indexed
// each node i > 1 gets a random parent in [1, i-1]
vector<pair<int, int>> rnd_tree(int n) {
  vector<pair<int, int>> edges;
  for (int i = 2; i <= n; i++)
    edges.push_back({(int)rnd(1, i - 1), i});
  return edges;
}

// random.random() < p  — true with probability p
bool coin(double p = 0.5) { return rnd01() < p; }

// ============================================================================
//  Two solutions to compare
// ============================================================================

namespace Fast {
// the solution you want to submit
long long solve(const vector<long long> &a) {
  long long best = 0, cur = 0;
  for (long long x : a) {
    cur = max(0LL, cur + x); // bug on purpose: ignores all-negative arrays
    best = max(best, cur);
  }
  return best;
}
} // namespace Fast

namespace Brute {
// slow but obviously correct (max subarray sum, O(n^2))
long long solve(const vector<long long> &a) {
  int n = a.size();
  long long best = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    long long s = 0;
    for (int j = i; j < n; j++) {
      s += a[j];
      best = max(best, s);
    }
  }
  return best;
}
} // namespace Brute

// ============================================================================
//  Driver
// ============================================================================

int main() {
  for (int test = 1;; test++) {
    // ---- generate a small random input (edit for the problem) ----
    int n = rnd(1, 5);
    vector<long long> a = rnd_array(n, -10, 10);

    // ---- run both ----
    long long out1 = Fast::solve(a);
    long long out2 = Brute::solve(a);

    // ---- compare ----
    if (out1 != out2) {
      cout << "MISMATCH on test " << test << '\n';
      cout << "n = " << n << '\n';
      cout << "a = ";
      for (long long x : a)
        cout << x << ' ';
      cout << '\n';
      cout << "fast  = " << out1 << '\n';
      cout << "brute = " << out2 << '\n';
      return 0;
    }

    if (test % 1000 == 0)
      cerr << test << " passed\r";
  }
}
# C++ STL Reference for Competitive Programming

Assumes `#include <bits/stdc++.h>` and `using namespace std;`. Signatures are simplified: `T` is the element type, `it` an iterator, `n` a count. Complexity is shown where it matters.

---

## 1. Template

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);   // don't sync with C stdio -> faster cin/cout
    cin.tie(nullptr);              // don't flush cout before every cin
    int t; cin >> t;
    while (t--) {
        // solve
    }
}
```

After `sync_with_stdio(false)` never mix `cin/cout` with `scanf/printf`.

---

## 2. Types and limits

| Type | Bytes | Range |
|---|---|---|
| `int` | 4 | −2,147,483,648 … 2,147,483,647 (≈ ±2.1·10⁹) |
| `long long` | 8 | ≈ ±9.2·10¹⁸ |
| `unsigned long long` | 8 | 0 … 1.8·10¹⁹ |
| `double` | 8 | ~15–16 significant digits |
| `long double` | 16 | ~18–19 digits, slower |
| `char` | 1 | −128 … 127, `'a'` is 97 |
| `bool` | 1 | `true` / `false` |

Constants: `INT_MAX`, `INT_MIN`, `LLONG_MAX`, `LLONG_MIN`. Or `numeric_limits<T>::max()`.

Rules:
- `int * int` overflows before assignment. Write `1LL * a * b`.
- `1 << 40` overflows. Write `1LL << 40`.
- Integer division truncates toward zero: `-7 / 2 == -3`.
- Modulo keeps the sign of the dividend: `-7 % 3 == -1`. Normalise with `((x % m) + m) % m`.
- `int / int` is integer division. `(double)a / b` for real division.
- Local `int x;` holds garbage. Initialise: `int x = 0;`. Globals are zero-initialised.

---

## 3. Input / output

```cpp
int n; cin >> n;                          // any number of >> chained
int a, b; cin >> a >> b;
string s; cin >> s;                       // reads one whitespace-delimited token
getline(cin, s);                          // reads whole line (call cin.ignore() first if a >> preceded it)
cout << x << ' ' << y << '\n';
cout << fixed << setprecision(9) << d;    // fixed decimals for doubles
```

Use `'\n'`, not `endl`. `endl` flushes the buffer every time and is slow in loops.

Reading until EOF: `while (cin >> x) { ... }`

---

## Container cheat table

| Container | Underlying structure | Access `[i]` | Insert / erase | Search | Ordered? |
|---|---|---|---|---|---|
| `vector<T>` | contiguous array | O(1) | O(1) at end, O(n) elsewhere | O(n) (O(log n) if sorted + `lower_bound`) | by index |
| `string` | contiguous array | O(1) | same as vector | O(n) | by index |
| `deque<T>` | chunked array | O(1) | O(1) both ends, O(n) middle | O(n) | by index |
| `list<T>` | doubly linked list | none | O(1) with iterator | O(n) | by position |
| `set<T>` / `map<K,V>` | red-black tree | none | O(log n) | O(log n) | yes, sorted |
| `multiset<T>` | red-black tree | none | O(log n) | O(log n) | yes, sorted |
| `unordered_set` / `unordered_map` | hash table | none | O(1) avg, O(n) worst | O(1) avg, O(n) worst | no |
| `stack<T>` / `queue<T>` | wraps deque | top / front only | O(1) | none | LIFO / FIFO |
| `priority_queue<T>` | binary heap | top only | O(log n) | none | max (or min) on top |

---

## 4. `vector<T>`  — dynamic array

Contiguous block of memory (not a linked list). Holds a pointer, a size and a capacity. When `push_back` runs out of capacity it allocates a new block about twice as large and copies everything over, so `push_back` is O(1) amortised. `reserve(n)` allocates once up front. Any iterator/pointer into the vector is invalid after a reallocation.

```cpp
vector<int> a;              // empty
vector<int> a(n);           // n zeros
vector<int> a(n, val);      // n copies of val
vector<int> a = {1, 2, 3};
vector<vector<int>> g(n, vector<int>(m, 0));   // n × m grid
vector<int> b(a.begin() + i, a.begin() + j);   // copy of a[i..j)
```

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `a[i]` | `T& operator[](size_t i)` | O(1) | **no bounds check**; reading past the end is silent garbage |
| `at` | `T& at(size_t i)` | O(1) | throws on bad index, use when debugging |
| `front` / `back` | `T& front()` / `T& back()` | O(1) | UB on empty |
| `push_back` | `void push_back(const T& x)` | O(1) amortised | |
| `pop_back` | `void pop_back()` | O(1) | returns nothing; read `back()` first |
| `size` | `size_t size()` | O(1) | **unsigned**. `(int)a.size() - 1` |
| `empty` | `bool empty()` | O(1) | |
| `clear` | `void clear()` | O(n) | size becomes 0, capacity kept |
| `resize` | `void resize(n)` / `resize(n, val)` | O(n) | |
| `assign` | `void assign(n, val)` | O(n) | overwrite whole vector |
| `reserve` | `void reserve(n)` | O(n) once | avoids repeated reallocation |
| `insert` | `it insert(it pos, const T& x)` | O(n) | shifts everything after `pos` |
| `erase` | `it erase(it pos)` / `it erase(it first, it last)` | O(n) | shifts everything after |
| `begin` / `end` | `it begin()` / `it end()` | O(1) | `end()` is one past last |
| `rbegin` / `rend` | reverse iterators | O(1) | `sort(a.rbegin(), a.rend())` = descending |

Iterating:
```cpp
for (int i = 0; i < (int)a.size(); i++) use(a[i]);
for (int x : a) ...          // copy of each element
for (auto &x : a) cin >> x;  // reference, modifies a
```

Passing to a function: `void f(vector<int> &a)` or `void f(const vector<int> &a)`. Without `&` the whole vector is copied, O(n).

`list<T>` is the doubly linked list. O(1) insert/erase anywhere given an iterator, but no `[]` and bad cache behaviour. Almost never worth it in CP.

## 5. `string`

```cpp
string s;                 // ""
string s(n, 'x');         // n copies of 'x'
string s = "abc";
```

A `string` is a `vector<char>` with extra methods; same contiguous layout and same complexities.

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `s[i]` | `char& operator[](size_t i)` | O(1) | mutable: `s[0] = 'z'` |
| `size` / `length` | `size_t size()` | O(1) | unsigned |
| `push_back` | `void push_back(char c)` | O(1) amortised | |
| `pop_back` | `void pop_back()` | O(1) | |
| `back` / `front` | `char& back()` | O(1) | |
| `s += t` | `string& operator+=(const string&)` / `(char)` | O(len t) amortised | |
| `s + t` | `string operator+(const string&, const string&)` | O(n + m) | makes a new string; in a loop prefer `+=` |
| `substr` | `string substr(size_t pos, size_t len = npos)` | O(len) | (start, **length**) |
| `find` | `size_t find(const string& t, size_t from = 0)` | O(n·m) worst | returns `string::npos` if absent |
| `rfind` | `size_t rfind(const string& t)` | O(n·m) worst | last occurrence |
| `insert` | `string& insert(size_t pos, const string& t)` | O(n) | |
| `erase` | `string& erase(size_t pos, size_t len)` | O(n) | |
| `compare` / `==` / `<` | `int compare(const string& t)` | O(min(n, m)) | <0, 0, >0 |
| `c_str` | `const char* c_str()` | O(1) | for `printf("%s")` |

Comparison operators `==`, `<`, etc. work lexicographically.

Conversions:
```cpp
int    x = stoi(s);          // "123" -> 123, throws on garbage
ll     x = stoll(s);
double d = stod(s);
string s = to_string(123);   // works for int, ll, double
```

Character helpers (`<cctype>`): `isdigit(c)`, `isalpha(c)`, `isalnum(c)`, `islower(c)`, `isupper(c)`, `tolower(c)`, `toupper(c)`. All take and return `int`; cast result: `char(tolower(c))`.

Char arithmetic: `'5' - '0' == 5`, `c - 'a'` gives 0..25, `char('a' + i)` back to a letter.

Build from chars: `string s(v.begin(), v.end())` where `v` is `vector<char>`.

`stringstream` for splitting a line by spaces:
```cpp
stringstream ss(line);
string word;
while (ss >> word) ...
```

---

## 6. `pair<A,B>` and `tuple<A,B,C>`

```cpp
pair<int,int> p = {1, 2};
p.first; p.second;
auto p = make_pair(1, 2);
auto [x, y] = p;                     // structured binding (C++17)

tuple<int,int,int> t = {1, 2, 3};
get<0>(t); get<1>(t);
auto [a, b, c] = t;
```

Pairs compare lexicographically (`first` then `second`), so `sort` on `vector<pair<int,int>>` works without a comparator. Same for tuples.

---

## 7. `map<K,V>` — sorted associative array (red-black tree, O(log n))

```cpp
map<string,int> m;
m["abc"] = 5;
m["abc"]++;               // creates with 0 if absent, then increments
```

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `m[k]` | `V& operator[](const K& k)` | O(log n) | **inserts default if missing** |
| `at` | `V& at(const K& k)` | O(log n) | throws if missing |
| `count` | `size_t count(const K& k)` | O(log n) | 0 or 1; the safe "contains" check |
| `find` | `it find(const K& k)` | O(log n) | `end()` if missing; `it->first`, `it->second` |
| `insert` | `pair<it,bool> insert({k, v})` | O(log n) | does not overwrite existing |
| `erase` | `size_t erase(const K& k)` / `it erase(it)` | O(log n) | |
| `size` / `empty` | | O(1) | |
| `clear` | | O(n) | |
| `lower_bound` | `it lower_bound(const K& k)` | O(log n) | first key ≥ k |
| `upper_bound` | `it upper_bound(const K& k)` | O(log n) | first key > k |
| `begin` / `rbegin` | | O(1) | smallest / largest key |
| iterate all | `for (auto& [k, v] : m)` | O(n) | in key order |

```cpp
for (auto &[k, v] : m) cout << k << ' ' << v << '\n';   // sorted by key
if (m.count(k)) ...
auto it = m.find(k); if (it != m.end()) use(it->second);
```

Do not call `m[k]` just to test membership: it inserts.

---

## 8. `unordered_map<K,V>` — hash table (average O(1))

Same interface as `map` minus `lower_bound`/`upper_bound` and no ordering. Works for `int`, `ll`, `string`; does **not** work for `pair` keys without a custom hash.

| Operation | Average | Worst |
|---|---|---|
| `[]`, `at`, `find`, `count`, `insert`, `erase` | O(1) | O(n) |
| iterate all | O(n) | |

On Codeforces, `unordered_map` can be hacked to O(n) per operation with adversarial input. In rated rounds prefer `map`, or use a custom hash:

```cpp
struct custom_hash {
    size_t operator()(uint64_t x) const {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};
unordered_map<ll, int, custom_hash> m;
```

---

## 9. `set<T>` / `multiset<T>` — sorted unique / sorted with duplicates (O(log n))

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `insert` | `pair<it,bool> insert(const T& x)` | O(log n) | multiset returns `it` |
| `erase` | `size_t erase(const T& x)` | O(log n + k) | **multiset: erases ALL k copies** |
| `erase` | `it erase(it pos)` | O(1) amortised | erases one element; `s.erase(s.find(x))` removes one copy from multiset |
| `count` | `size_t count(const T& x)` | O(log n + k) | k = number of copies |
| `find` | `it find(const T& x)` | O(log n) | |
| `lower_bound` | `it lower_bound(const T& x)` | O(log n) | first ≥ x. **Use the member**; `std::lower_bound(s.begin(), s.end(), x)` is O(n) on a set |
| `upper_bound` | `it upper_bound(const T& x)` | O(log n) | first > x |
| `begin` / `rbegin` | | O(1) | min / max |
| `prev(it)` / `next(it)` | | O(1) amortised | move one step in sorted order |
| `size` / `empty` | | O(1) | |
| `clear` | | O(n) | |

```cpp
set<int> s;
*s.begin();                     // min
*s.rbegin();                    // max
*prev(s.end());                 // also max
auto it = s.lower_bound(x);     // check it != s.end() before dereferencing
if (it != s.begin()) --it;      // largest element < x  (after lower_bound)
```

`unordered_set<T>` has the same interface minus ordering/bounds: O(1) average, O(n) worst per operation.

---

## 10. `deque`, `queue`, `stack`, `priority_queue`

| Container | Operations | Complexity | Layout |
|---|---|---|---|
| `deque<T>` | `push_front/back`, `pop_front/back`, `front`, `back`, `d[i]`, `size`, `empty` | all O(1) | chunked array |
| `queue<T>` | `push`, `front`, `pop`, `size`, `empty` | all O(1) | wraps deque |
| `stack<T>` | `push`, `top`, `pop`, `size`, `empty` | all O(1) | wraps deque |
| `priority_queue<T>` | `push`, `pop` | O(log n) | binary heap in a vector |
| | `top`, `size`, `empty` | O(1) | |

None of them can be iterated over except `deque`. `pop` returns nothing; read `front`/`top` first.

### `deque<T>`
```cpp
deque<int> d;
d.push_front(x); d.push_back(x);
d.pop_front();   d.pop_back();
d.front(); d.back(); d[i];
```
Used for sliding-window minimum and 0-1 BFS.

### `queue<T>` — FIFO
```cpp
queue<int> q;
q.push(x);        // void push(const T&)
q.front();        // T& front()
q.pop();          // void pop()
```

### `stack<T>` — LIFO
```cpp
stack<int> st;
st.push(x); st.top(); st.pop();
```
A `vector` with `push_back/back/pop_back` does the same and is often simpler.

### `priority_queue<T>` — heap
```cpp
priority_queue<int> pq;                                  // MAX on top (default)
priority_queue<int, vector<int>, greater<int>> pq;       // MIN on top
priority_queue<pair<int,int>> pq;                        // max by .first, then .second
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;  // min-heap of pairs
pq.push(x); pq.top(); pq.pop();
```
Standard for Dijkstra: `pq.push({dist, node})`.

## 11. Algorithms (`<algorithm>`, `<numeric>`)

All take iterator ranges `[first, last)`. For a vector use `a.begin(), a.end()`; for part of it `a.begin() + i, a.begin() + j`.

### Sorting and ordering
| Function | Signature | Complexity | Note |
|---|---|---|---|
| `sort` | `void sort(it first, it last)` / `sort(first, last, cmp)` | O(n log n) | not stable |
| `stable_sort` | same | O(n log n) | keeps equal elements in order |
| `reverse` | `void reverse(it first, it last)` | O(n) | in place |
| `nth_element` | `void nth_element(first, first + k, last)` | O(n) average | puts k-th smallest at index k |
| `next_permutation` | `bool next_permutation(first, last)` | O(n) | returns false after last permutation; n! total |
| `is_sorted` | `bool is_sorted(first, last)` | O(n) | |

Custom comparator: returns `true` if `x` must come before `y`. Must be a strict weak ordering (never return true for equal elements; use `<`, not `<=`).
```cpp
sort(a.begin(), a.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
    if (x.second != y.second) return x.second < y.second;
    return x.first < y.first;
});
sort(a.begin(), a.end(), greater<int>());   // descending
```

### Searching (sorted ranges only for the *_bound ones)
| Function | Signature | Complexity | Note |
|---|---|---|---|
| `lower_bound` | `it lower_bound(first, last, val)` | O(log n) | first element ≥ val; range must be sorted and random-access |
| `upper_bound` | `it upper_bound(first, last, val)` | O(log n) | first element > val |
| `binary_search` | `bool binary_search(first, last, val)` | O(log n) | |
| `find` | `it find(first, last, val)` | O(n) | any range |
| `count` | `int count(first, last, val)` | O(n) | |
| `find_if` / `count_if` | `(first, last, pred)` | O(n) | with a lambda |

Convert iterator to index: `lower_bound(...) - a.begin()`.
Number of elements equal to `v` in sorted `a`: `upper_bound(...) - lower_bound(...)`.

### Min / max / sum
| Function | Signature | Complexity | Note |
|---|---|---|---|
| `max` / `min` | `T max(a, b)` / `max({a, b, c})` | O(1) | same type required: `max(x, 0LL)` not `max(x, 0)` if x is ll |
| `max_element` | `it max_element(first, last)` | O(n) | returns iterator, dereference with `*` |
| `min_element` | `it min_element(first, last)` | O(n) | |
| `minmax_element` | `pair<it,it> minmax_element(first, last)` | O(n) | |
| `accumulate` | `T accumulate(first, last, T init)` | O(n) | **type of `init` sets the sum type**: use `0LL` |
| `partial_sum` | `partial_sum(first, last, out_first)` | O(n) | prefix sums into another range |

### Modifying
| Function | Signature | Complexity | Note |
|---|---|---|---|
| `fill` | `void fill(first, last, val)` | O(n) | |
| `iota` | `void iota(first, last, start)` | O(n) | fills start, start+1, … |
| `unique` | `it unique(first, last)` | O(n) | removes **consecutive** duplicates, returns new logical end; sort first |
| `swap` | `void swap(a, b)` | O(1) | O(1) even for two vectors (swaps pointers) |
| `copy` | `copy(first, last, out_first)` | O(n) | |
| `rotate` | `rotate(first, middle, last)` | O(n) | |
| `shuffle` | `shuffle(first, last, rng)` | O(n) | see §13 for `rng` |

Dedup a vector:
```cpp
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
```

### Math
| Function | Complexity | Note |
|---|---|---|
| `abs(x)` | O(1) | works for int, ll, double |
| `gcd(a, b)`, `lcm(a, b)` | O(log min(a,b)) | C++17. `lcm` can overflow: `a / gcd(a,b) * b` |
| `pow(b, e)` | O(1) | returns **double**, imprecise for ints. Write your own for integers |
| `sqrt(x)` | O(1) | double. For integer sqrt use `sqrtl` then adjust ±1 |
| `ceil`, `floor`, `round` | O(1) | return double |
| `__builtin_popcount(x)` / `__builtin_popcountll(x)` | O(1) | number of set bits |
| `__builtin_clz(x)` / `__builtin_ctz(x)` | O(1) | leading / trailing zeros (UB on 0) |
| `__lg(x)` | O(1) | floor(log2(x)) |

Ceil division for positive ints: `(a + b - 1) / b`.

---

## 12. Functions, lambdas, references

```cpp
int f(int x) { return x * 2; }                      // by value
void g(vector<int>& a) { a.push_back(1); }          // by reference: modifies caller's
ll h(const vector<int>& a) { return a.size(); }     // read-only reference: no copy
```

Lambdas:
```cpp
auto sq = [](int x) { return x * x; };
auto cmp = [&](int i, int j) { return a[i] < a[j]; };   // [&] captures outer vars by reference
```

Recursive lambda (avoids globals):
```cpp
function<int(int)> fact = [&](int n) { return n <= 1 ? 1 : n * fact(n - 1); };
```
Or `auto dfs = [&](auto&& self, int u) -> void { ... self(self, v); ... }; dfs(dfs, 0);` (faster than `std::function`).

Structured bindings: `auto [a, b] = p;`, `for (auto& [k, v] : m)`.

`auto` deduces the type: `auto it = s.find(x);`

---

## 13. Misc

**Random:**
```cpp
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int r = rng() % n;                                   // or
uniform_int_distribution<int>(lo, hi)(rng);
```

**Fixed-size arrays:** `int a[N];` globally (zero-initialised, can be 10⁷). Large local arrays overflow the stack. `memset(a, 0, sizeof a)` resets; `memset(a, -1, sizeof a)` sets all to −1 (works for 0 and −1 only). Or `fill(a, a + n, val)`.

**`bitset<N>`:** fixed-size bit array. `b.set(i)`, `b.reset(i)`, `b[i]`, `b.count()`, bitwise ops `& | ^ << >>`. 64× faster than `vector<bool>` for bit-parallel DP.

**Modular arithmetic:**
```cpp
const ll MOD = 1e9 + 7;
ll power(ll b, ll e) {
    ll r = 1; b %= MOD;
    while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
    return r;
}
ll inv(ll x) { return power(x, MOD - 2); }   // MOD must be prime
```

**Timing:** ~10⁸ simple operations per second. n = 2·10⁵ allows O(n log n); n = 5·10³ allows O(n²); n = 20 allows O(2ⁿ).

**Codeforces compiler:** newest GNU G++, 64-bit.

---

## 14. Errors and what they usually mean

| Symptom | Likely cause |
|---|---|
| Wrong answer on large tests only | `int` overflow → use `ll` |
| Runtime error / crash | out-of-bounds index, empty `.back()`/`.top()`, deep recursion, division by zero |
| TLE with correct algorithm | `endl` in a loop, passing vectors by value, `unordered_map` hacked, `std::lower_bound` on a `set` |
| Nonsense values | uninitialised local variable or array |
| Infinite loop on empty input | `a.size() - 1` underflow (unsigned) |
| Wrong answer with negatives | `/` truncating, `%` negative |
| Same answer every test case | forgot to reset a global between test cases |
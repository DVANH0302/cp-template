# C++ STL Reference for Competitive Programming

Assumes `#include <bits/stdc++.h>` and `using namespace std;`.
`T` = element type, `it` = iterator, `n` = count, `K`/`V` = key/value type.

> Click a link to jump. Every container/algorithm section follows the same shape:
> **declare → operations table → gotchas**, so once you know the shape you can scan fast.

---

## Table of Contents

- [0. Which container do I want?](#0-which-container-do-i-want)
- [1. Template & fast I/O](#1-template--fast-io)
- [2. Types, limits, overflow](#2-types-limits-overflow)
- [3. `vector<T>`](#3-vectort)
- [4. `string`](#4-string)
- [5. `pair` / `tuple`](#5-pair--tuple)
- [6. `map<K,V>`](#6-mapkv)
- [7. `unordered_map<K,V>`](#7-unordered_mapkv)
- [8. `set<T>` / `multiset<T>`](#8-sett--multisett)
- [9. `deque` / `queue` / `stack` / `priority_queue`](#9-deque--queue--stack--priority_queue)
- [10. Algorithms (`<algorithm>`, `<numeric>`)](#10-algorithms-algorithm-numeric)
- [11. Functions, lambdas, references](#11-functions-lambdas-references)
- [12. Misc (random, arrays, bitset, modular math, timing)](#12-misc-random-arrays-bitset-modular-math-timing)
- [13. Symptom → likely cause](#13-symptom--likely-cause)

---

## 0. Which container do I want?

| Need | Container | Why |
|---|---|---|
| Indexed list, grows at the end | `vector<T>` | O(1) amortised push_back, O(1) index |
| Grows/shrinks at **both** ends | `deque<T>` | O(1) both ends |
| Key → value, need sorted order or range queries | `map<K,V>` | O(log n), iterates sorted |
| Key → value, only need fast lookup | `unordered_map<K,V>` | O(1) avg — but hackable on CF, see §7 |
| Unique sorted values, need min/max/neighbors fast | `set<T>` | O(log n), `begin()`/`rbegin()` |
| Same but duplicates allowed | `multiset<T>` | |
| LIFO | `stack<T>` (or just a `vector`) | |
| FIFO | `queue<T>` | |
| Repeatedly need the min or max element | `priority_queue<T>` | O(log n) push/pop |
| Sliding window min/max, 0-1 BFS | `deque<T>` | push/pop both ends |

[↑ back to top](#table-of-contents)

---

## 1. Template & fast I/O

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

> ⚠️ After `sync_with_stdio(false)`, never mix `cin`/`cout` with `scanf`/`printf`.

**I/O quick reference**

```cpp
int n; cin >> n;                          // chain any number of >>
string s; cin >> s;                       // one whitespace-delimited token
getline(cin, s);                          // whole line (cin.ignore() first if a >> came before)
cout << x << ' ' << y << '\n';            // use '\n', not endl (endl flushes = slow in loops)
cout << fixed << setprecision(9) << d;    // fixed decimals for doubles
while (cin >> x) { ... }                  // read until EOF
```

[↑ back to top](#table-of-contents)

---

## 2. Types, limits, overflow

| Type | Bytes | Range |
|---|---|---|
| `int` | 4 | ±2.1·10⁹ |
| `long long` | 8 | ±9.2·10¹⁸ |
| `unsigned long long` | 8 | 0 … 1.8·10¹⁹ |
| `double` | 8 | ~15–16 sig. digits |
| `long double` | 16 | ~18–19 digits, slower |
| `char` | 1 | −128…127, `'a'` = 97 |
| `bool` | 1 | `true` / `false` |

Constants: `INT_MAX`, `INT_MIN`, `LLONG_MAX`, `LLONG_MIN`, or `numeric_limits<T>::max()`.

**Rules to not get burned:**
- `int * int` overflows before assignment → write `1LL * a * b`
- `1 << 40` overflows → write `1LL << 40`
- Integer division truncates toward zero: `-7 / 2 == -3`
- `%` keeps the sign of the dividend: `-7 % 3 == -1` → normalise with `((x % m) + m) % m`
- `int / int` truncates → `(double)a / b` for real division
- Local `int x;` holds garbage — always initialise. Globals are zero-initialised for free.

[↑ back to top](#table-of-contents)

---

## 3. `vector<T>`

Contiguous array: pointer + size + capacity. `push_back` doubles capacity when full (O(1) amortised); `reserve(n)` avoids repeated reallocation. **Any iterator/pointer is invalidated after a reallocation.**

```cpp
vector<int> a;                                 // empty
vector<int> a(n);                              // n zeros
vector<int> a(n, val);                         // n copies of val
vector<int> a = {1, 2, 3};
vector<vector<int>> g(n, vector<int>(m, 0));   // n × m grid
vector<int> b(a.begin() + i, a.begin() + j);   // copy of a[i..j)
```

<details>
<summary><strong>Operations</strong></summary>

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `a[i]` | `T& operator[](size_t)` | O(1) | **no bounds check** |
| `at` | `T& at(size_t)` | O(1) | throws on bad index — good for debugging |
| `front` / `back` | `T& front()/back()` | O(1) | UB on empty |
| `push_back` | `void push_back(x)` | O(1) amortised | |
| `pop_back` | `void pop_back()` | O(1) | returns nothing — read `back()` first |
| `size` | `size_t size()` | O(1) | **unsigned**: `(int)a.size() - 1` |
| `empty` | `bool empty()` | O(1) | |
| `clear` | `void clear()` | O(n) | size → 0, capacity kept |
| `resize` | `resize(n)` / `resize(n, val)` | O(n) | |
| `assign` | `assign(n, val)` | O(n) | overwrite whole vector |
| `reserve` | `reserve(n)` | O(n) once | |
| `insert` | `it insert(it pos, x)` | O(n) | shifts everything after |
| `erase` | `it erase(it)` / `erase(first,last)` | O(n) | shifts everything after |
| `begin`/`end` | | O(1) | `end()` is one-past-last |
| `rbegin`/`rend` | | O(1) | `sort(a.rbegin(), a.rend())` = descending |

</details>

**Iterating & passing**

```cpp
for (int i = 0; i < (int)a.size(); i++) use(a[i]);
for (int x : a) ...          // copy
for (auto &x : a) cin >> x;  // reference, modifies a

void f(vector<int> &a);        // by reference — no copy
void f(const vector<int> &a);  // read-only, no copy
void f(vector<int> a);         // COPIES the whole vector — O(n), avoid in hot paths
```

> `list<T>` = doubly linked list. O(1) insert/erase given an iterator, but no `[]`, bad cache locality. Almost never worth it in CP.

[↑ back to top](#table-of-contents)

---

## 4. `string`

A `vector<char>` with extra methods — same layout, same complexities as §3.

```cpp
string s;                 // ""
string s(n, 'x');         // n copies of 'x'
string s = "abc";
```

<details>
<summary><strong>Operations</strong></summary>

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `s[i]` | `char& operator[](size_t)` | O(1) | mutable |
| `size`/`length` | | O(1) | unsigned |
| `push_back`/`pop_back` | `char c` | O(1) amortised | |
| `back`/`front` | | O(1) | |
| `s += t` | | O(len t) amortised | prefer over `+` in a loop |
| `s + t` | | O(n+m) | allocates a new string |
| `substr` | `substr(pos, len=npos)` | O(len) | **(start, length)**, not (start, end) |
| `find` | `find(t, from=0)` | O(n·m) worst | returns `string::npos` if absent |
| `rfind` | `rfind(t)` | O(n·m) worst | last occurrence |
| `insert` | `insert(pos, t)` | O(n) | |
| `erase` | `erase(pos, len)` | O(n) | |
| `compare`/`==`/`<` | | O(min(n,m)) | lexicographic |
| `c_str` | | O(1) | for `printf("%s")` |

</details>

**Conversions**
```cpp
int    x = stoi(s);          // throws on garbage
ll     x = stoll(s);
double d = stod(s);
string s = to_string(123);   // works for int, ll, double
```

**Char helpers** (`<cctype>`, all take/return `int`): `isdigit`, `isalpha`, `isalnum`, `islower`, `isupper`, `tolower`, `toupper` — cast the result: `char(tolower(c))`.

**Char arithmetic:** `'5' - '0' == 5`, `c - 'a'` → 0..25, `char('a' + i)` → letter.

**Build from chars:** `string s(v.begin(), v.end())` where `v` is `vector<char>`.

**Split a line by spaces:**
```cpp
stringstream ss(line);
string word;
while (ss >> word) ...
```

[↑ back to top](#table-of-contents)

---

## 5. `pair` / `tuple`

```cpp
pair<int,int> p = {1, 2};
p.first; p.second;
auto p = make_pair(1, 2);
auto [x, y] = p;                     // structured binding (C++17)

tuple<int,int,int> t = {1, 2, 3};
get<0>(t); get<1>(t);
auto [a, b, c] = t;
```

> Pairs/tuples compare lexicographically (first field first), so `sort` on `vector<pair<...>>` works with no comparator.

[↑ back to top](#table-of-contents)

---

## 6. `map<K,V>`

Red-black tree, sorted by key, O(log n).

```cpp
map<string,int> m;
m["abc"] = 5;
m["abc"]++;               // creates with 0 if absent, then increments
```

<details>
<summary><strong>Operations</strong></summary>

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `m[k]` | `V& operator[](k)` | O(log n) | **inserts default if missing** |
| `at` | `V& at(k)` | O(log n) | throws if missing |
| `count` | `size_t count(k)` | O(log n) | 0 or 1 — the safe "contains" check |
| `find` | `it find(k)` | O(log n) | `end()` if missing |
| `insert` | `insert({k,v})` | O(log n) | does **not** overwrite existing |
| `erase` | `erase(k)` / `erase(it)` | O(log n) | |
| `size`/`empty`/`clear` | | O(1) / O(n) | |
| `lower_bound` | `it lower_bound(k)` | O(log n) | first key ≥ k |
| `upper_bound` | `it upper_bound(k)` | O(log n) | first key > k |
| `begin`/`rbegin` | | O(1) | smallest / largest key |
| iterate all | `for (auto& [k,v] : m)` | O(n) | **in key order** |

</details>

```cpp
if (m.count(k)) ...
auto it = m.find(k); if (it != m.end()) use(it->second);
```

> ⚠️ Never call `m[k]` just to test membership — it inserts a default value as a side effect.

[↑ back to top](#table-of-contents)

---

## 7. `unordered_map<K,V>`

Hash table, average O(1). Same interface as `map` minus `lower_bound`/`upper_bound`, no ordering. Works for `int`/`ll`/`string`; **not** for `pair` keys without a custom hash.

| Operation | Average | Worst |
|---|---|---|
| `[]`, `at`, `find`, `count`, `insert`, `erase` | O(1) | O(n) |
| iterate all | O(n) | |

> ⚠️ On Codeforces, `unordered_map` can be **hacked** to O(n) per op with adversarial input. In rated rounds prefer `map`, or use a custom hash:

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

[↑ back to top](#table-of-contents)

---

## 8. `set<T>` / `multiset<T>`

Sorted, O(log n). `set` = unique values, `multiset` = duplicates allowed.

<details>
<summary><strong>Operations</strong></summary>

| Method | Signature | Complexity | Note |
|---|---|---|---|
| `insert` | `insert(x)` | O(log n) | multiset returns an `it` |
| `erase` | `erase(x)` | O(log n + k) | **multiset: erases ALL k copies** |
| `erase` | `erase(it)` | O(1) amortised | erases one element; `s.erase(s.find(x))` = remove one copy from multiset |
| `count` | `count(x)` | O(log n + k) | k = number of copies |
| `find` | `find(x)` | O(log n) | |
| `lower_bound` | `lower_bound(x)` | O(log n) | first ≥ x — **use the member function**, not `std::lower_bound` (that's O(n) on a set) |
| `upper_bound` | `upper_bound(x)` | O(log n) | first > x |
| `begin`/`rbegin` | | O(1) | min / max |
| `prev(it)`/`next(it)` | | O(1) amortised | step in sorted order |
| `size`/`empty`/`clear` | | O(1) / O(n) | |

</details>

```cpp
set<int> s;
*s.begin();                     // min
*s.rbegin();                    // max
*prev(s.end());                 // also max
auto it = s.lower_bound(x);     // check it != s.end() before dereferencing
if (it != s.begin()) --it;      // largest element < x (after lower_bound)
```

> `unordered_set<T>` = same interface minus ordering/bounds: O(1) average, O(n) worst.

[↑ back to top](#table-of-contents)

---

## 9. `deque` / `queue` / `stack` / `priority_queue`

None except `deque` can be iterated. `pop`/`pop_front`/`pop_back` return nothing — read `front`/`top`/`back` first.

| Container | Ops | Complexity | Layout |
|---|---|---|---|
| `deque<T>` | `push_front/back`, `pop_front/back`, `front`, `back`, `d[i]`, `size`, `empty` | all O(1) | chunked array |
| `queue<T>` | `push`, `front`, `pop`, `size`, `empty` | all O(1) | wraps deque, FIFO |
| `stack<T>` | `push`, `top`, `pop`, `size`, `empty` | all O(1) | wraps deque, LIFO |
| `priority_queue<T>` | `push`, `pop` (O(log n)), `top`/`size`/`empty` (O(1)) | | binary heap |

```cpp
deque<int> d;
d.push_front(x); d.push_back(x);
d.pop_front();   d.pop_back();
// used for: sliding-window min/max, 0-1 BFS

queue<int> q;
q.push(x); q.front(); q.pop();

stack<int> st;                  // a vector with push_back/back/pop_back works too, often simpler
st.push(x); st.top(); st.pop();

priority_queue<int> pq;                                              // max on top (default)
priority_queue<int, vector<int>, greater<int>> pq;                   // min on top
priority_queue<pair<int,int>> pq;                                    // max by .first then .second
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;  // min-heap of pairs
// Dijkstra: pq.push({dist, node});
```

[↑ back to top](#table-of-contents)

---

## 10. Algorithms (`<algorithm>`, `<numeric>`)

All take iterator ranges `[first, last)` — for a vector: `a.begin(), a.end()`, or a slice `a.begin()+i, a.begin()+j`.

<details>
<summary><strong>Sorting & ordering</strong></summary>

| Function | Signature | Complexity | Note |
|---|---|---|---|
| `sort` | `sort(first,last[,cmp])` | O(n log n) | not stable |
| `stable_sort` | same | O(n log n) | keeps equal elements in order |
| `reverse` | `reverse(first,last)` | O(n) | in place |
| `nth_element` | `nth_element(first, first+k, last)` | O(n) avg | k-th smallest ends at index k |
| `next_permutation` | `next_permutation(first,last)` | O(n) | false after last permutation; n! total |
| `is_sorted` | `is_sorted(first,last)` | O(n) | |

```cpp
sort(a.begin(), a.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
    if (x.second != y.second) return x.second < y.second;
    return x.first < y.first;
});
sort(a.begin(), a.end(), greater<int>());   // descending
```
> Comparator must return `true` if `x` strictly comes before `y`. Never return `true` for equal elements (use `<`, not `<=`).

</details>

<details>
<summary><strong>Searching (sorted ranges only for *_bound)</strong></summary>

| Function | Signature | Complexity | Note |
|---|---|---|---|
| `lower_bound` | `lower_bound(first,last,val)` | O(log n) | first element ≥ val; needs sorted + random-access |
| `upper_bound` | `upper_bound(first,last,val)` | O(log n) | first element > val |
| `binary_search` | `binary_search(first,last,val)` | O(log n) | |
| `find` | `find(first,last,val)` | O(n) | any range |
| `count` | `count(first,last,val)` | O(n) | |
| `find_if`/`count_if` | `(first,last,pred)` | O(n) | with a lambda |

```cpp
lower_bound(...) - a.begin();                      // iterator → index
upper_bound(...) - lower_bound(...);               // count of elements == v in sorted a
```

</details>

<details>
<summary><strong>Min / max / sum</strong></summary>

| Function | Signature | Complexity | Note |
|---|---|---|---|
| `max`/`min` | `max(a,b)` / `max({a,b,c})` | O(1) | same type required: `max(x, 0LL)` not `max(x, 0)` if x is ll |
| `max_element`/`min_element` | `it max_element(first,last)` | O(n) | dereference with `*` |
| `minmax_element` | `pair<it,it>` | O(n) | |
| `accumulate` | `accumulate(first,last,init)` | O(n) | **type of `init` sets the sum type** — use `0LL` |
| `partial_sum` | `partial_sum(first,last,out)` | O(n) | prefix sums into another range |

</details>

<details>
<summary><strong>Modifying</strong></summary>

| Function | Signature | Complexity | Note |
|---|---|---|---|
| `fill` | `fill(first,last,val)` | O(n) | |
| `iota` | `iota(first,last,start)` | O(n) | fills start, start+1, … |
| `unique` | `unique(first,last)` | O(n) | removes **consecutive** dupes only — sort first |
| `swap` | `swap(a,b)` | O(1) | even for two vectors (swaps pointers) |
| `copy` | `copy(first,last,out)` | O(n) | |
| `rotate` | `rotate(first,middle,last)` | O(n) | |
| `shuffle` | `shuffle(first,last,rng)` | O(n) | see §12 for `rng` |

```cpp
// Dedup a vector:
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
```

</details>

<details>
<summary><strong>Math</strong></summary>

| Function | Complexity | Note |
|---|---|---|
| `abs(x)` | O(1) | int, ll, double |
| `gcd(a,b)`, `lcm(a,b)` | O(log min(a,b)) | C++17; `lcm` can overflow → `a / gcd(a,b) * b` |
| `pow(b,e)` | O(1) | returns **double**, imprecise for ints — write your own for integers |
| `sqrt(x)` | O(1) | double; for integer sqrt use `sqrtl` then adjust ±1 |
| `ceil`/`floor`/`round` | O(1) | return double |
| `__builtin_popcount(x)`/`popcountll(x)` | O(1) | # set bits |
| `__builtin_clz(x)`/`ctz(x)` | O(1) | leading/trailing zeros — UB on 0 |
| `__lg(x)` | O(1) | floor(log2(x)) |

Ceil division for positive ints: `(a + b - 1) / b`.

</details>

[↑ back to top](#table-of-contents)

---

## 11. Functions, lambdas, references

```cpp
int f(int x) { return x * 2; }                      // by value
void g(vector<int>& a) { a.push_back(1); }          // by reference: modifies caller's
ll h(const vector<int>& a) { return a.size(); }     // read-only reference: no copy

auto sq  = [](int x) { return x * x; };
auto cmp = [&](int i, int j) { return a[i] < a[j]; };   // [&] captures outer vars by reference

// Recursive lambda (avoids globals):
function<int(int)> fact = [&](int n) { return n <= 1 ? 1 : n * fact(n - 1); };
// faster alternative to std::function:
auto dfs = [&](auto&& self, int u) -> void { /* ... */ self(self, v); /* ... */ };
dfs(dfs, 0);

auto [a, b] = p;                 // structured bindings
for (auto& [k, v] : m) ...
auto it = s.find(x);             // auto deduces the type
```

[↑ back to top](#table-of-contents)

---

## 12. Misc (random, arrays, bitset, modular math, timing)

**Random**
```cpp
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int r = rng() % n;                                   // or
uniform_int_distribution<int>(lo, hi)(rng);
```

**Fixed-size arrays**
```cpp
int a[N];                       // global: zero-initialised, can be 10^7
memset(a, 0, sizeof a);         // reset to 0
memset(a, -1, sizeof a);        // works ONLY for 0 and -1
fill(a, a + n, val);            // any other value
```
> Large **local** arrays overflow the stack — put big arrays at global scope.

**`bitset<N>`**
Fixed-size bit array. `b.set(i)`, `b.reset(i)`, `b[i]`, `b.count()`, bitwise `& | ^ << >>`. ~64× faster than `vector<bool>` for bit-parallel DP.

**Modular arithmetic**
```cpp
const ll MOD = 1e9 + 7;
ll power(ll b, ll e) {
    ll r = 1; b %= MOD;
    while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
    return r;
}
ll inv(ll x) { return power(x, MOD - 2); }   // MOD must be prime
```

**Timing rule of thumb:** ~10⁸ simple ops/sec.

| n | feasible complexity |
|---|---|
| 2·10⁵ | O(n log n) |
| 5·10³ | O(n²) |
| 20 | O(2ⁿ) |

Codeforces compiler: newest GNU G++, 64-bit.

[↑ back to top](#table-of-contents)

---

## 13. Symptom → likely cause

| Symptom | Likely cause |
|---|---|
| Wrong answer on large tests only | `int` overflow → use `ll` |
| Runtime error / crash | out-of-bounds index, empty `.back()`/`.top()`, deep recursion, division by zero |
| TLE with correct algorithm | `endl` in a loop, passing vectors by value, `unordered_map` hacked, `std::lower_bound` on a `set` |
| Nonsense values | uninitialised local variable or array |
| Infinite loop on empty input | `a.size() - 1` underflow (unsigned) |
| Wrong answer with negatives | `/` truncating, `%` negative |
| Same answer every test case | forgot to reset a global between test cases |

[↑ back to top](#table-of-contents)
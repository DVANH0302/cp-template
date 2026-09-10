# Combinatorics Revision Notes

## 1. The Two Basic Rules

- **AND rule (multiplication):** If task A can be done in $m$ ways and task B in $n$ ways, and you do **both at once**, total ways = $m \times n$.
- **OR rule (addition):** If you can do task A **or** task B (not both), total ways = $m + n$.

Everything below is built from just these two rules.

---

## 2. Arranging Distinct Items (Permutations)

Arranging $n$ **different** items in a row: fill position 1 ($n$ choices), position 2 ($n-1$ choices left), etc.

$$n! = n \times (n-1) \times \cdots \times 1$$

Example: arrange A, B, C → $3! = 6$ ways.

---

## 3. Arranging Items With Duplicates

**Problem:** arrange letters like A, A, B, C (one letter repeated).

**Key idea:** first _pretend_ the duplicates are different (label them A₁, A₂). Count normally: $4! = 24$.

But every _real_ arrangement got counted multiple times — once for each way to swap the labels on the duplicate. Swapping A₁ and A₂ never changes what you actually see, so:

$$N_{\text{labeled}} = N_{\text{real}} \times (\text{ways to relabel duplicates})$$

For one pair of duplicates, relabeling = $2!$ ways. So:

$$N_{\text{real}} = \frac{n!}{2!}$$

**General formula** (multiple repeated letters, counts $k_1, k_2, \dots$):

$$\frac{n!}{k_1!\, k_2! \cdots}$$

**Rule of thumb:** whenever a count is inflated by "these items look different in my counting method but are actually identical," find how many ways to relabel/reorder those identical items, and divide by that.

---

## 4. Choosing Without Order (Combinations)

**Problem:** choose $r$ items out of $n$ **distinct** items, order doesn't matter.

**Step 1 — count with order (Permutation / Arrangement):**

$$P(n,r) = A(n,r) = \frac{n!}{(n-r)!} = n \times (n-1) \times \cdots \times (n-r+1)$$

**Step 2 — fix overcounting:** each _group_ of $r$ items got counted once per possible ordering of that group, i.e. $r!$ times. Divide it out:

$$C(n,r) = \binom{n}{r} = \frac{P(n,r)}{r!} = \frac{n!}{r!(n-r)!}$$

**Relationship:** $P(n,r) = C(n,r) \times r!$

**Notation:** $C(n,r) = \binom{n}{r} = nCr$ (order doesn't matter); $P(n,r) = A(n,r) = nPr$ (order matters). Same math, different countries/books use different letters.

**Symmetry identity:** $\binom{n}{r} = \binom{n}{n-r}$ — choosing $r$ to include = choosing $n-r$ to exclude. Same act, described from either side.

---

## 5. ⚠️ When Division Does NOT Work

Division only works when **every** real outcome is overcounted by the **same** fixed amount. Test this before trusting a shortcut — try a small example and list all outcomes by hand.

**Example that breaks:** string A, A, B, C — choose 2 _different_ letters.

- Treating the A's as different gives $\binom{4}{2}=6$ position-pairs.
- But pairs like {A,B} get counted **twice** (via A₁ or A₂), while {B,C} is counted **once**. Uneven → no single division fixes it.

**Fix:** don't count positions — count **distinct types** directly:

$$\binom{k}{r}, \quad k = \text{number of distinct types available}$$

For AABC choosing 2 different letters: $k=3$ types (A,B,C) → $\binom{3}{2}=3$. Correct.

**General lesson:** if a shortcut formula only worked on one example, test it on a _different_ example before trusting it. If the "overcount ratio" changes between examples, no fixed divisor/formula exists — you need casework or a different counting method entirely.

---

## 6. Partitioning Into Groups

**Problem:** split 8 distinct items into groups of size 4, 2, 2.

**Step 1 — labeled groups** (as if each group had a name):

$$\binom{8}{4}\binom{4}{2}\binom{2}{2} = \frac{8!}{4!\,2!\,2!} = 420$$

**Step 2 — unlabeled groups** (two groups share the same size 2, so swapping which is "first" and "second" is not a new outcome): divide by $2!$ for the number of same-size groups that could be swapped:

$$\frac{420}{2!} = 210$$

**Rule of thumb:** divide by $k!$ for every set of $k$ groups that are the same size **and** have no distinguishing label.

---

## 7. Distinguishable Balls Into Labeled Bins

**Problem:** 12 distinct balls into 3 labeled bins A, B, C — no restrictions.

Each ball independently picks a bin (3 choices), and all 12 choices happen simultaneously (AND rule):

$$3^{12}$$

**No division needed** — every outcome here really is distinct (different ball → different bin assignment = genuinely different result). No hidden duplicates.

---

## 8. Identical Balls Into Labeled Bins (Stars and Bars)

**Problem:** if the balls are _identical_, "each ball has 3 choices" stops making sense — there's no "ball #1" to track anymore. $3^{12}$ divided by anything does **not** work (tested and confirmed with small cases — the overcount ratio isn't even constant).

**Correct method — Stars and Bars:**

Represent $n$ identical balls as $n$ stars in a row. Insert $k-1$ bars to divide them into $k$ bins:

$$\bigstar\bigstar\,|\,\bigstar\bigstar\bigstar\,|\,\bigstar\bigstar\bigstar\bigstar\bigstar\bigstar\bigstar$$

Every arrangement of stars+bars = exactly one way to split the balls. Total symbols = $n + (k-1)$. Choose which positions are bars (or equivalently, which are stars):

$$\binom{n+k-1}{k-1} = \binom{n+k-1}{n}$$

(These two are equal — choosing bar-positions vs. choosing star-positions is the same act seen from two sides, same as $\binom{n}{r}=\binom{n}{n-r}$.)

**Example:** 12 balls, 3 bins → $\binom{14}{2} = \binom{14}{12} = 91$.

---

## 9. Grid Paths (Right/Down Only)

**Problem:** count paths in a grid from $(0,0)$ to $(m,n)$, moving only right or down.

**Recurrence (built from the OR rule):** to arrive at $(i,j)$, the last move was either from above (down-move) or from the left (right-move) — mutually exclusive, covers everything:

$$\text{ways}(i,j) = \text{ways}(i-1,j) + \text{ways}(i,j-1)$$

**Closed-form shortcut:** any full path has exactly $m$ down-moves and $n$ right-moves in some order, total $m+n$ moves. Choosing which of the $m+n$ move-slots are "down" (rest are "right") is a pure combination:

$$\binom{m+n}{m}$$

The recurrence and the binomial coefficient give the same answer — recurrence is the step-by-step (DP) view, the binomial coefficient is the direct formula.

---

## Quick Reference Table

| Situation                                                               | Formula                                                            |
| ----------------------------------------------------------------------- | ------------------------------------------------------------------ |
| Arrange $n$ distinct items                                              | $n!$                                                               |
| Arrange $n$ items with repeats ($k_1,k_2,\dots$ copies)                 | $\dfrac{n!}{k_1!k_2!\cdots}$                                       |
| Choose $r$ from $n$, order matters                                      | $P(n,r)=\dfrac{n!}{(n-r)!}$                                        |
| Choose $r$ from $n$, order doesn't matter                               | $C(n,r)=\dbinom{n}{r}=\dfrac{n!}{r!(n-r)!}$                        |
| Choose $r$ distinct **types** with duplicates present                   | $\dbinom{k}{r}$, $k$ = # distinct types                            |
| Split $n$ distinct items into groups of sizes $n_1,n_2,\dots$ (labeled) | $\dfrac{n!}{n_1!n_2!\cdots}$                                       |
| Same, but groups of equal size are unlabeled                            | divide further by $j!$ per group of $j$ same-size unlabeled groups |
| $n$ distinct items into $k$ labeled bins, no capacity limit             | $k^n$                                                              |
| $n$ **identical** items into $k$ labeled bins (stars and bars)          | $\dbinom{n+k-1}{k-1}$                                              |
| Grid paths, right/down only, $(0,0)\to(m,n)$                            | $\dbinom{m+n}{m}$                                                  |

## The One Meta-Lesson

Whenever you're tempted to fix an overcounted number by dividing: **check with a tiny example first.** If every real outcome is overcounted by the _same_ fixed amount, division works. If the overcount is _uneven_ across outcomes (as with duplicates mixed with unique items), division fails — you need casework, or a genuinely different counting method (like stars and bars) that counts the right objects from the start.

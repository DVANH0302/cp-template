# Modular Division — Summary

## The problem

Addition, subtraction, and multiplication all distribute nicely over mod:

```
(a + b) mod M = (a mod M + b mod M) mod M
(a - b) mod M = (a mod M - b mod M + M) mod M
(a * b) mod M = (a mod M * b mod M) mod M
```

**Division does not work this way.** You cannot just divide `a mod M` by `b mod M`.

Counterexample: `16 ≡ 1 (mod 5)`, but `16/2 mod 5 = 3` while `1/2` isn't even a valid mod operation.

## The fix: modular inverse

Instead of dividing by `b`, multiply by `b`'s **modular inverse** — a number `b⁻¹` such that:

```
b * b⁻¹ ≡ 1 (mod M)
```

Then:

```
a / b mod M  =  (a * b⁻¹) mod M
```

`b⁻¹` acts like "1/b" inside modular arithmetic.

**Requirement:** the inverse only exists if `gcd(b, M) = 1` (b and M share no common factor).

## ⭐ The one formula to remember (competitive programming)

```
a / b mod M  =  a * b^(M-2) mod M
```

Derived from Fermat's Little Theorem: `b^(M-1) ≡ 1 (mod M)` → split exponent → `b * b^(M-2) ≡ 1 (mod M)` → so `b^(M-2)` _is_ the inverse.

**Only valid when:**

1. **M is prime** (Fermat's theorem requires this)
2. **b is not a multiple of M** (i.e. `gcd(b, M) = 1`)

In practice: almost every CP problem uses `M = 1e9+7` or `998244353` (both prime), and `b` is basically never a multiple of `M` — so this formula covers nearly all cases.

```cpp
int binPow(int x, int y, int mod) {
    int ret = 1;
    for (; y; y /= 2, x = 1ll * x * x % mod)
        if (y % 2) ret = 1ll * ret * x % mod;
    return ret;
}

int inv(int x, int mod) {
    return binPow(x, mod - 2, mod);
}

int divMod(int a, int b, int mod) {
    return 1ll * a * inv(b) % mod;
}
```

## If M is NOT prime (edge case, rarer)

| Case                                                 | Method                                                                                                             |
| ---------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------ |
| `gcd(b, M) = 1` (M composite but still coprime to b) | Use **Extended Euclidean Algorithm** to solve `bx + My = 1`; `x` is the inverse                                    |
| `gcd(b, M) ≠ 1` (no inverse exists)                  | Use `a/b mod M = (a mod (b*M)) / b` — requires `b divides a` exactly, and must use the _original_ b, not `b mod M` |

## Bottom line

- Default in CP: `a * b^(M-2) mod M`, with M prime.
- If M isn't prime → switch to Extended Euclid.
- If no inverse exists at all → use the `b*M` trick (needs `b | a`).

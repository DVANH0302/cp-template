First, a small correction to your framing: the difference array isn't specifically about updating the *same* range many times. It helps with **any** many range updates, overlapping or not. The updates can hit completely different ranges. What matters is that each update costs O(1) instead of O(length of range).

Now the real question: why can you touch only the endpoints?

## The core reasoning

The key is what `d` actually *means*. Each `d[i]` answers one question:

> "How much higher is `a[i]` than `a[i-1]`?"

So `d` doesn't store values. It stores **changes between neighbors**. Once you see that, the rest follows from one observation.

**If you add the same amount `v` to two neighbors, their gap doesn't change.**

```
a[i-1] = 7, a[i] = 9   → gap = 2
add 5 to both:
a[i-1] = 12, a[i] = 14 → gap = 2
```

Now apply that to a range update on `[l, r]`. Every element in the range gets `+v`. Consider each neighbor pair:

- **Both inside the range** (pairs `(l, l+1)`, `(l+1, l+2)`, ..., `(r-1, r)`): both rose by `v`, so the gap is unchanged. `d` doesn't change at all for these. That's the entire middle of the range, and we skip all of it.
- **Pair `(l-1, l)`**: only the right side rose. The gap grew by `v`. So `d[l] += v`.
- **Pair `(r, r+1)`**: only the left side rose. The gap shrank by `v`. So `d[r+1] -= v`.
- **Pairs completely outside the range**: neither rose, no change.

So exactly **two** gaps change, the ones at the boundary where you cross into and out of the range. That's why only endpoints need editing.

## Where the "work" goes

The middle elements do get changed in `a`, but we don't touch them now. Instead we defer the work: the prefix sum at the end **carries the `+v` across the range automatically**.

Think of it as a wave:

```
d[l] += v      → "starting here, everything is v higher"
d[r+1] -= v    → "starting here, stop being v higher"
```

The prefix sum passes the `+v` along every position from `l` to `r`, then cancels it at `r+1`. One pass at the end does the propagation for *all* updates at once, instead of each update doing its own propagation.

## The one-sentence version

A range update is a "step up at `l`, step down at `r+1`" in the array's shape, and a difference array stores exactly the steps, so you only record the two places the shape changes.

Does the neighbor-gap picture make sense? If not, tell me which part is fuzzy and I'll redo it with a different example.
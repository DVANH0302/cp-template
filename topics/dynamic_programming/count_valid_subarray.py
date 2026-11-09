"""
Count subarrays x of arr (length >= 2 effectively) where the first occurrence of
min(x) is strictly left of the first occurrence of max(x).
Divide and conquer, O(n log n).
"""
import sys
import random

sys.setrecursionlimit(10000)


def count_valid(arr):
    def solve(L, R):  # half-open [L, R)
        if R - L <= 1:
            return 0

        mid = (L + R) // 2
        m = R - mid

        # Right half prefixes: arr[mid..mid+j]
        pre_max, pre_min = [], []
        good_r_cum = [0] * (m + 1)  # good_r_cum[k] = number of good j in [0, k)
        cur_max, cur_min = arr[mid], arr[mid]
        arg_max = arg_min = mid
        for j in range(m):
            v = arr[mid + j]
            if v > cur_max:          # strict: keep first occurrence
                cur_max, arg_max = v, mid + j
            if v < cur_min:
                cur_min, arg_min = v, mid + j
            pre_max.append(cur_max)
            pre_min.append(cur_min)
            good_r_cum[j + 1] = good_r_cum[j] + (1 if arg_min < arg_max else 0)

        # Left half suffixes: arr[i..mid-1], i going leftwards, with two pointers
        count = 0
        p1 = 0  # first j where pre_max[j] > sufMax  (max moves to the right)
        p2 = 0  # first j where pre_min[j] < sufMin  (min moves to the right)
        s_max = s_min = arr[mid - 1]
        a_max = a_min = mid - 1
        for i in range(mid - 1, L - 1, -1):
            v = arr[i]
            if v >= s_max:           # extending left: ties move first occurrence to i
                s_max, a_max = v, i
            if v <= s_min:
                s_min, a_min = v, i

            while p1 < m and pre_max[p1] <= s_max:
                p1 += 1
            while p2 < m and pre_min[p2] >= s_min:
                p2 += 1

            lo, hi = (p1, p2) if p1 < p2 else (p2, p1)

            # both extremes in the left half
            if a_min < a_max:
                count += lo
            # max in right, min in left
            if p1 < p2:
                count += p2 - p1
            # both extremes in the right half
            count += good_r_cum[m] - good_r_cum[hi]

        return count + solve(L, mid) + solve(mid, R)

    return solve(0, len(arr))


def brute(a):
    n, cnt = len(a), 0
    for i in range(n):
        for j in range(i + 1, n):
            seg = a[i:j + 1]
            if seg.index(min(seg)) < seg.index(max(seg)):
                cnt += 1
    return cnt


if __name__ == "__main__":
    print(count_valid([1, 5, 2, 3]))  # expected 4

    random.seed(1)
    for t in range(20000):
        n = random.randint(1, 12)
        a = [random.randint(0, random.choice([2, 5, 20])) for _ in range(n)]
        assert count_valid(a) == brute(a), (a, count_valid(a), brute(a))
    print("random tests passed")
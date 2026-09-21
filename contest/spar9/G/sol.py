import sys
input = sys.stdin.readline

def solve(k, a, b):
    direct = abs(a - b)

    a_candidates = [
        (a % k, a - (a % k)),           # lower
        (k - a % k, a + (k - a % k))    # upper
    ]

    b_candidates = [
        (b % k, b - (b % k)),           # lower
        (k - b % k, b + (k - b % k))    # upper
    ]

    ans = direct

    for cost_a, multiple_a in a_candidates:
        for cost_b, multiple_b in b_candidates:
            vaults = abs(multiple_a - multiple_b) // k
            ans = min(ans, cost_a + cost_b + vaults)

    return ans


def main():
    k, a, b = map(int, input().split())
    print(solve(k, a, b))


if __name__ == '__main__':
    main()
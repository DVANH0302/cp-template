import sys
input = sys.stdin.readline



def binary_search(l, r, g, prefix):
    
    sub = prefix[l-1] if l > 0 else 0

    while l < r:
        mid = (l + r) // 2
        if prefix[mid] - sub  >= 0:
            r = mid
        else:
            l = mid + 1
    return r


def solve(n, g, p):
    prefix = [0] * n
    prefix[0] = p[0]
    res = [0] * n
    for i in range(1, n):
        prefix[i] = prefix[i-1] + p[i]
    
    for i in range(n):
        res[i] = binary_search(i, n, g, prefix)
    return res

def main():
    n = int(input())
    g = list(map(int, input().split()))
    p = list(map(int, input().split()))
    out = solve(n, g, p)
    print(' '.join([str(num) for num in out]))

if __name__ == '__main__':
    main()
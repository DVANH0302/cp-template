import sys
input = sys.stdin.readline


def precompute(end):
    F = [0] * (max(3,end+1))
    mod = 10**9 + 7
    F[1] = 1
    F[2] = 1 
    for i in range(3, end+1):
        F[i] =  (F[i-1] + F[i-2]) % mod

    return F

def solve(n,q,arr,queries, F):
    Fa = [F[num] for num in arr]
    mod = 10 ** 9 + 7
    res = []
    prefix = [0] * n
    prefix[0] = Fa[0] 

    for l, r in queries:
        cur = 0
        for i in range(l-1, r):
            cur += Fa[i] % mod
        res.append(cur)

    return res  

def main():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    queries = []
    for _ in range(q): 
        l, r = map(int, input().split())
        queries.append((l,r))
    F = precompute(max(arr))
    out = solve(n,q,arr,queries, F)
    print('\n'.join([str(r) for r in out]))

if __name__ == '__main__':
    main()
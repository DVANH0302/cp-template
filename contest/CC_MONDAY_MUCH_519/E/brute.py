import sys
import math
input = sys.stdin.readline

def solve(n, k, arr):
    if n == 1:
        return 0 
    def dfs(i):
        nonlocal k
        if i == n:
            # print(arr)
            return max(arr) - min(arr)
        best = math.inf
        arr[i] += k
        r1 = dfs(i+1)
        best = min(best, r1)
        arr[i] -= k

        if arr[i] -k >= 0:
            arr[i] -= k
            r2 = dfs(i+1)
            best = min(best, r2)
            arr[i] += k
        return best
    
    return dfs(0)

def main():
    # n, k = list(map(int, input().split()))

    # arr = list(map(int, input().split()))
    n = 4 
    k = 1 
    arr = [2, 13, 15, 4]
    print(solve(n,k,arr))

if __name__ == '__main__':
    main()
import sys
input = sys.stdin.readline

def solve(n, k, arr):
    if n == 1:
        return 0 
    arr.sort()
    best = arr[n-1] - arr[0]

    for i in range(0, n-1):
        min1, max1 = arr[0] + k, arr[i] + k
        min2, max2 = arr[i+1] - k, arr[n-1] - k

        if min2 < 0:
            continue 

        best = min(best, max(max1, max2) - min(min1, min2))

    return best

def main():
    n, k = list(map(int, input().split()))

    arr = list(map(int, input().split()))
    print(solve(n,k,arr))

if __name__ == '__main__':
    main()
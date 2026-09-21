import sys
input = sys.stdin.readline

def solve(n, arr):
    return sum(arr)

def main():
    # n = int(input())
    n, m = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    queries = []
    for _ in range(m):
        queries.append()
    print(solve(n, arr))

if __name__ == '__main__':
    main()
import sys
input = sys.stdin.readline

def solve(n, arr):
    res = [n- i for i in arr ]
    return max(res)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        print(solve(n, arr))

if __name__ == '__main__':
    main()
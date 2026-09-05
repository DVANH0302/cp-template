import sys
input = sys.stdin.readline

def solve(n, arr):
    return sum(arr)

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(n, arr))

if __name__ == '__main__':
    main()
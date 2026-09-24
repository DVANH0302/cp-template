import sys
input = sys.stdin.readline

def solve(a,b,c):
    return max(abs(a-b), abs(a+c-b))

def main():
    t = int(input())
    for _ in range(t):
        a, b, c = list(map(int, input().split()))
        print(solve(a,b,c))

if __name__ == '__main__':
    main()
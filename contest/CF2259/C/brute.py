def solve(n, arr):
    best = 0
    for i in range(n):
        for j in range(n):
            ...  # naive version of the logic
    return best

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(n, arr))

if __name__ == '__main__':
    main()
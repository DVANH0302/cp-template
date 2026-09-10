import sys
input = sys.stdin.readline

def solve(n,m,arr):
    for i in range(n):
        arr[i] = arr[i] >> m

    return arr
    

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    m = int(input())
    arr = solve(n,m, arr)
    print(' '.join([str(num) for num in arr]))

if __name__ == '__main__':
    main()
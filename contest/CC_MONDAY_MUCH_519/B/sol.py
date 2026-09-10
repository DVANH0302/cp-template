import sys
input = sys.stdin.readline

def solve(n, k, arr):
    target = 2 * k 
    s = 0 

    for  i in range(0, n, 2):
        if arr[i] > target:
            s += arr[i]
    return s 
def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    print(solve(n, k,  arr))

if __name__ == '__main__':
    main()
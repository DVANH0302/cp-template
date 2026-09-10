import sys
input = sys.stdin.readline

def solve(n, arr):
    if n == 2:
        if arr == [0, 0]:
            return 0
        else:
            return -1

    if arr[0] == 0 and arr[n-1] == 0:
        return 0

    zeroes = arr.count(0)

    if zeroes < 2:
        return -1       

    if arr[0] == 0 or arr[n-1] == 0:
        return 1

    return 2
        


def main():
    t = int(input())
    out = []
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        out.append(solve(n, arr))
    print('\n'.join([str(res) for res in out]))

if __name__ == '__main__':
    main()
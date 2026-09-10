import sys
input = sys.stdin.readline

def solve(n, arr):
    bl, br = -1, -2

    min_minus_1 = -1
    for i in range(n):
        if arr[i] == -1:
            min_minus_1 = i
            break

    recentOnes = -1
    for i in range(n):
        if arr[i] != 0:
            if recentOnes == -1 and min_minus_1 != -1 and  i-min_minus_1+1 > br -bl+1:
                bl, br = min_minus_1, i
            elif recentOnes != -1 and i - recentOnes + 1 > br-bl+1:
                bl, br = recentOnes, i
            if arr[i] == 1:
                recentOnes = i
    if bl < 0 and br < 0:
        return arr
    arr[bl], arr[br] = 1, 1
    for i in range(n):
        if arr[i] == -1:
            arr[i] = 0
    # print(bl, br)
    return arr


    

def main():
    out = []
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        res = solve(n, arr)
        out.append(' '.join([str(num) for num in res]))
    print('\n'.join(out))
if __name__ == '__main__':
    main()
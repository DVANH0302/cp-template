import sys
input = sys.stdin.readline

def solve(n, c):
    suffix_min = [(0,0)] * n # (idx, val)
    cur_min = (n-1, c[n-1])
    suffix_min[n-1] = cur_min
    for i in range(n-2, -1, -1):
        if c[i] < cur_min[1]:
            cur_min = (i, c[i])
        suffix_min[i] = cur_min
    
    i = -1
    cost = 0 
    while i+1 < n:
        target = suffix_min[i+1]
        cost += (target[0] - i) * target[1]
        i = target[0]
        # print(cost, i)
    # print(suffix_min)
    return cost
def main():
    n = int(input())
    c = list(map(int, input().split()))
    print(solve(n, c))

if __name__ == '__main__':
    main()
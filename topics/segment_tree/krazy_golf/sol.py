import sys
import math
import random

input = sys.stdin.readline



def build(a, tree, node, l , r):
    if l == r:
        tree[node] = a[l]
        return tree[node]

    mid = (l + r) // 2
    leftMin = build(a, tree, node * 2 + 1, l, mid)
    rightMin = build(a, tree, node * 2 + 2, mid+1, r)

    tree[node] = min(leftMin, rightMin)
    return tree[node]

def query(a, tree, node, start, end, l, r, target):
    if tree[node] >= target or start > r or end < l:
        return -1

    if start == end:
        return start

    mid = (start + end) // 2
    
    left_ans = query(a, tree, node*2+1, start, mid, l, r, target)
    if left_ans != -1:
        return left_ans

    return query(a, tree, node*2+2, mid+1, end, l, r, target)
        



def solve(n,g,p):
    res = [0] * n
    prefix = [0] * n 
    prefix[0] = p[0]
    for i in range(1, n):
        prefix[i] = prefix[i-1] + p[i]
    diff = [prefix[i] - g[i] for i in range(n)]
    
    tree = [0] * (4 * n)
    build(diff, tree, 0, 0, n-1)

    for i in range(n):
        target = 0 if i == 0 else prefix[i-1]
        dieAt = query(diff, tree, 0, 0, n-1, i, n-1, target)
        if dieAt == -1:
            res[i] = n-i
        else:
            res[i] = dieAt-i+1
    return res


def main():
    n = int(input())
    g = list(map(int, input().split()))
    p = list(map(int, input().split()))
    print(" ".join(list(map(str, solve(n,g,p)))))

if __name__ == '__main__':
    main()
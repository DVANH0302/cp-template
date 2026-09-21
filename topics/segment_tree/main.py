import math
import random


def build(node, l , r):
    if l == r:
        tree[node] = a[l]
        return tree[node]

    mid = (l + r) // 2
    leftSum = build(node * 2 + 1, l, mid)
    rightSum = build(node * 2 + 2, mid+1, r)

    tree[node] = leftSum + rightSum

    return tree[node]


def update(node, tl, tr, idx, val):
    if tr < idx or tl > idx:
        return 
    
    if tl == idx and tr == idx:
        tree[node] = val
        return 
    
    mid = (tl + tr) // 2
    update(node * 2 +1, tl, mid, idx , val)
    update(node * 2 + 2, mid+1, tr, idx, val)

    tree[node] = tree[node*2+1] + tree[node*2+2]


def query(node, start, end, l, r):
    if r < start or end < l:        # no overlap
        return 0
    if l <= start and end <= r:     # total overlap
        return tree[node]
    mid = (start + end) // 2        # partial overlap
    return (query(2*node+1, start, mid, l, r) +
            query(2*node+2, mid+1, end, l, r))




def brute(l, r):
    s = 0 
    for i in range(l, r+1):
        s += a[i]
    return s


a = [1, 3, -2, 8, -7]
n = len(a)
tree = [0] * (4 * n)
build(0, 0, n-1)

def test():



    for _ in range(100):
        
        
        
        l = random.randint(0, n-1)
        r = random.randint(0, n-1)
        if l > r:
            l, r = r, l
        print('a before', a)
        # update
        i = random.randint(l, r)
        random_value = random.randint(-10, 10)
        a[i] = random_value
        update(0, 0, n-1, i, random_value)
        print('a after', a)
        q = query(0, 0, n-1, l, r)
        b = brute(l, r)

        if q != b:
            print(f"WRONG: a:{a},(l,r):{(l, r)}, q:{q}, b:{b}") 
            return
    print("OK")
test()
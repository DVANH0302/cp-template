import sys
import bisect
input = sys.stdin.readline

class SegmentTree:
    def __init__(self, arr):
        n = len(arr)
        self.t = [None] * (4 * n)
        self.arr = arr
        self.build(1, 0, n-1)

    def build(self, node, l, r):
        t = self.t
        arr = self.arr

        if l == r:
            t[node] = [arr[l]]
            return 
        
        mid = (l + r) // 2
        self.build(node * 2, l, mid)
        self.build(node * 2 + 1, mid+1, r)

        t[node] = []
        c1, c2 = t[2 * node], t[2 * node + 1]
        i1, i2 = 0, 0

        while i1 < len(c1) and i2 < len(c2):
            if c1[i1] < c2[i2]:
                t[node].append(c1[i1])
                i1 += 1 
            else:
                t[node].append((c2[i2]))
                i2 += 1 
        while i1 < len(c1):
            t[node].append(c1[i1])
            i1 += 1 
        while i2 < len(c2):
            t[node].append(c2[i2])
            i2 += 1 

    def query(self, node, tl, tr, l, r, k):
        t = self.t
        if tl > r or tr < l:
            return 0
        if l <= tl and tr <= r:
            largerIndex = bisect.bisect_right(t[node], k)
            return len(t[node]) - largerIndex

        tm = (tl + tr) // 2
        return self.query(2*node, tl, tm, l, r, k) + self.query(2*node+1, tm+1, tr, l, r, k)

def solve(n, q, arr, queries):
    n = len(arr)
    st = SegmentTree(arr)
    res = []


    for i,j,k in queries:
        res.append(st.query(1, 0, n-1, i-1, j-1, k))

    return res

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    q = int(input())
    queries = []
    for _ in range(q):
        i, j, k = list(map(int, input().split()))
        queries.append((i, j, k))
    
    qrs = list(map(str, solve(n, q, arr, queries)))  

    print('\n'.join(qrs))


if __name__ == '__main__':
    main()
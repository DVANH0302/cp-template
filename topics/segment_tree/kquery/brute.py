def solve(n, q, arr, queries):
    n = len(arr)
    res = []

    for i,j,k in queries:
        c = 0 
        for x in range(i-1, j):
            if arr[x] > k: 
                c += 1
        res.append(c)

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
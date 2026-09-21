import sys
import heapq
input = sys.stdin.readline

def solve(n, m, arr):
    maxHeap = []
    curSum = 0
    score = 0
    for i in range(m-1):
        curSum += arr[i]
        heapq.heappush(maxHeap, -arr[i])
    # print(arr, m)
    score = m * arr[m-1] - curSum
    for i in range(m-1, n-1):
        heapq.heappush(maxHeap, -arr[i])
        negav_popped = heapq.heappop(maxHeap)
        popped = negav_popped * (-1)
        curSum +=  arr[i] - popped
        score = max(score, m * arr[i+1] - curSum)
    
    return score

def main():
    t = int(input())
    out = []
    for _ in range(t):
        n, m = list(map(int, input().split()))
        arr = list(map(int, input().split()))
        # print(n, m , arr)
        out.append(solve(n,m, arr))
    print('\n'.join([str(res) for res in out]))
if __name__ == '__main__':
    main()
import sys
input = sys.stdin.readline

def solve(n, p):
    invalids = []
    for i, num in enumerate(p):
        if num != i+1:
            invalids.append(i)
    l = 0 
    r = len(invalids) - 1 

    while l < r:
        p[invalids[l]], p[invalids[r]] = p[invalids[r]], p[invalids[l]]
        l += 1
        r -= 1
    
    for i, num in enumerate(p):
        if num != i+1:
            return "NO"
    return "YES"



def main():
    t = int(input())
    for _ in range(t):
        n = int(input())    
        p = list(map(int, input().split()))
        print(solve(n, p))

if __name__ == '__main__':
    main()
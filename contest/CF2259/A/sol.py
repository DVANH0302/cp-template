import sys
input = sys.stdin.readline

def solve(n,k,s):
    f = 0
    pay = 0
    while f <= n-k:
        free = False
        for i in range(f, f+k):
            if s[i] == '0':
                free = True 
                break

        if not free:
            pay += 1 
        f += k
    return pay

def main():
    t = int(input())
    out = []
    for _ in range(t):
        n, k = list(map(int, input().split()))
        s = input().rstrip()
        out.append(solve(n,k,s))
    print('\n'.join([str(res) for res in out]))
if __name__ == '__main__':
    main()
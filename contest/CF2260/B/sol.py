import sys
input = sys.stdin.readline

def solve(x,y,k):
    d = y - x
    total = 0
    
    i = 0
    while i < k and x + i <= d:
        total += (y+i) % (x +i)
        i += 1

    if k - i > 0:
        total += (k - i) * d
    return total


def main():
    t = int(input())
    out = []
    for _ in range(t):
        x,y,k= list(map(int, input().split()))
        out.append(solve(x,y,k))
    print('\n'.join([str(res) for res in out]))


if __name__ == '__main__':
    main()
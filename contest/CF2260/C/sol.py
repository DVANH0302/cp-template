import sys
input = sys.stdin.readline

def solve(x, y):

    if x + y == x ^ y:
        return " ".join([str(y+x), "0"])


    maxi =  y + x 
    
    nx = x.bit_length()

    newX = 0
    for i in range(nx-1, -1, -1):
        if maxi & (1 << i)  != 0 and newX + 2 ** i <= x:
            newX += 2 ** i
    
    out = [maxi, x - newX]

    return " ".join([str(num) for num in out])

def main():
    t = int(input())
    out = []
    for _ in range(t):
        x,y = list(map(int, input().split()))
        out.append(solve(x, y))
    print('\n'.join(out))

if __name__ == '__main__':
    main()
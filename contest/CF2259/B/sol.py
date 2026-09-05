import sys
input = sys.stdin.readline

def solve(n, arr):
    odd = 0 
    even1 = 0 
    even2 =  0    
    for num in arr:
        if num % 2 == 1:
            odd += 1 
        elif num % 4 == 0:
            even2 += 1 
        elif num % 2 == 0:
            even1 += 1 

    return max(odd, even1, even2)
def main():
    t = int(input())
    out = []
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        out.append(solve(n, arr))
    print('\n'.join([str(res) for res in out]))

if __name__ == '__main__':
    main()
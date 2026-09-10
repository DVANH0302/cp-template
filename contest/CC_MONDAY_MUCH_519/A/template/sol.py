import sys
input = sys.stdin.readline



def main():
    
    a, b, x = list(map(int, input().split()))

    res = "YES" if a + b >= x else "NO"

    print(res)

if __name__ == '__main__':
    main()
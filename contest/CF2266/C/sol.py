import sys
import math
# from functools import cache
input = sys.stdin.readline


# @cache
# def solve(n, s):
#     def dp(i, prev):

#         if i == n:
#             return 0

#         if prev == 1:
#             if s[i] == '0':
#                 return 1 + dp(i+1, 1)
#             elif s[i] == '1':
#                 return dp(i+1, 1)
#         if prev == 0:
#             if s[i] == '0':
#                 return dp(i+1, 0)
#             elif s[i] == '1':
#                 return min(
#                     dp(i+1, 1),
#                     1+dp(i+1, 0)
#                 )
#     prev = 1 if s[0] == '1' else 0
#     return dp(1, prev)

def solve(n, s):
    dp = [[math.inf] * 2 for _ in range(n+1)]
    dp[n][0], dp[n][1] = 0, 0

    for i in range(n-1, 0, -1):
        if s[i] == '0':
            dp[i][1] = 1 + dp[i+1][1]
            dp[i][0] = dp[i+1][0]
        else:
            dp[i][0] = min(
                dp[i+1][1],
                1+dp[i+1][0]
            )
            dp[i][1] = dp[i+1][1]
    
    start = 1 if s[0] == '1' else 0
    return dp[1][start]




def main():
    t=int(input())
    for _ in range(t):
        n = int(input())
        s= input().rstrip()
        print(solve(n, s))

if __name__ == '__main__':
    main()
from functools import lru_cache
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer


    def numDistinct(self, A, B):
        
        m = len(A)
        n = len(B)

        dp = [[0] * (n+1) for _ in range(m+1)]

        for i in range(m+1):
            dp[i][0] = 1
        

        for i in range(1, m+1):
            for j in range(1, n+1):
                if A[i-1] == B[j-1]:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[m][n]


A = "rabbbit" 
B = "rabbit"

print(Solution().numDistinct(A, B))
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
    def minDistance(self, A, B):
        m, n = len(A), len(B)
        dp = [[0] * (n+1) for _ in range(m+1)]

        for i in range(m+1):
            dp[i][n] = m-i
        
        for j in range(n+1):
            dp[m][j] = n-j
        

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if A[i] == B[j]:
                    dp[i][j] = dp[i+1][j+1]
                else:
                    dp[i][j] = 1 + min(
                        dp[i][j+1],
                        dp[i+1][j],
                        dp[i+1][j+1]
                    )
        return dp[0][0]
A = "abad"
B = "abac"

A = "Anshuman"
B = "Antihuman"
print(Solution().minDistance(A, B))

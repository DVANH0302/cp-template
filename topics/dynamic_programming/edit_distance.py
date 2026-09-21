class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
    def minDistance(self, A, B):
        m, n = len(A), len(B)
        memo = {}
        def dp(i, j):
            nonlocal m, n     
            if j == n:
                return m - i
            if i == m:
                return n - j

            if (i, j) in memo:
                return memo[(i, j)]

            if A[i] == B[j]:
                memo[(i, j)] = dp(i+1, j+1)
                return memo[(i,j)]
            
            memo[(i,j)] = 1 + min(
                dp(i, j+1),
                dp(i+1, j),
                dp(i+1, j+1)
            )
            return memo[(i, j)]
        return dp(0,0)
    
A = "abad"
B = "abac"

A = "Anshuman"
B = "Antihuman"
print(Solution().minDistance(A, B))
from functools import lru_cache
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer


    def numDistinct(self, A, B):
        
        @lru_cache(maxsize = None)
        def dp(i, j):
            # base case 

            if j < 0:
                return 1

            if i < 0:
                return 0 


            if A[i] == B[j]:
                return dp(i-1, j-1) + dp(i-1, j)
            else:
                return dp(i-1, j)

        return dp(len(A)-1, len(B)-1)

A = "rabbbit" 
B = "rabbit"

print(Solution().numDistinct(A, B))
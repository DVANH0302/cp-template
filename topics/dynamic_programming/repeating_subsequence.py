from functools import lru_cache
class Solution:
	# @param A : string
	# @return an integer

    @lru_cache(maxsize = None)
    def anytwo(self, A):
        n = len(A)
        def dp(i, j):
            nonlocal n 
            if i == n or j == n:
                return 0

            if i != j and A[i] == A[j]:
                return 1 + dp(i+1, j+1)
            else: 
                return max(dp(i+1, j), dp(i, j+1))
        return 1 if dp(0, 0) >= 2 else 0 

A = 'abab'
print(Solution().anytwo(A))
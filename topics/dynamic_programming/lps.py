class Solution:
    # @param A : string
    # @return an integer
    def solve(self, A):
        memo = {}
        def dp(l, r):
            if l > r:
                return 0      
            if l == r:
                return 1
                
            if (l, r) in memo:
                return memo[(l, r)]
            
            if A[l] == A[r]:
                memo[(l, r)] = 2 + dp(l+1, r-1)
                return memo[(l, r)]
            memo[(l, r)] = max(dp(l, r-1), dp(l+1, r))
            return memo[(l, r)]
        
        return dp(0, len(A)-1)

A = "bebeeed"
print(Solution().solve(A))
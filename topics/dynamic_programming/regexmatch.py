from functools import cache

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        
        @cache
        def dp(i, j):
            if i < 0 and j < 0:
                return True
            if j < 0:
                return False
            
            if j >= 0 and p[j] == '*':
                prev = p[j-1]
                if dp(i, j-2):
                    return True
                if i >= 0 and (s[i] == prev or prev == '.'):
                    return dp(i-1, j)
                return False
            
            if i >= 0 and (s[i] == p[j] or p[j] == '.'):
                return dp(i-1, j-1)
            
            return False
        
        return dp(n-1, m-1)
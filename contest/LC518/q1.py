class Solution:
    def countRotations(self, s: str, k: int) -> int:
        n = len(s)

        def score(s):
            n = len(s)
            score = 0
            for i in range(n-1):
                if s[i] == s[i+1]:
                    score += 1 
            return score


        res = 0 
        for i in range(n):
            if i == 0:
                newS = s
            else:
                newS = s[:n-i] + s[:i]
            curScore = score(newS)
            if curScore == k:
                res += 1 
        return res
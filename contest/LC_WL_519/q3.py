class Solution:
    def minDays(self, n: int) -> int:
        days = 0
        streak = 0 
        score = 0

        while score < n:
            streak += 1

            # if score + streak > n => reset 
            if score + streak > n:
                streak = 0
            
            score += streak
            days += 1
            print(days, streak, score)
        
        return days

n = 12
print(Solution().minDays(n))
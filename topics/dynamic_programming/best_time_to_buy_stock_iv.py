from functools import cache
class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        n = len(prices)
        @cache
        def dp(i, isHolding, ik):
            nonlocal n 

            if i == n or ik == k:
                return 0

            if isHolding == True:
                return max(
                    prices[i] + dp(i+1, False, ik+1),
                    dp(i+1, True, ik)
                )
            else:
                return max(
                    -prices[i] + dp(i+1, True, ik),
                    dp(i+1, False, ik )
                )
        return dp(0, False, 0)
prices = [3,2,6,5,0,3]
k = 2 
print(Solution().maxProfit(k, prices))
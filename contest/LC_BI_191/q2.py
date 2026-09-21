from collections import defaultdict
class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        d = defaultdict(list)
        for i, num in enumerate(nums):
            d[num].append(i)
        
        d = {k:v for k,v in d.items() if len(v) >= 3}
        res = 0
        for ls in d.values():
            d = ls[1] - ls[0]
            isValid = True
            for i in range(2,len(ls)):
                if ls[i] - ls[i-1] != d:
                    isValid = False
                    break
            if isValid:
                res += 1
        return res
from collections import defaultdict
class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        d = defaultdict(list)
        for i, num in enumerate(nums):
            d[num].append(i)
        
        d = {k:v for k,v in d.items() if len(v) == 3}
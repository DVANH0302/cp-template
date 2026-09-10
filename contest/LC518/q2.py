class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)
        p = [0] * n 
        p[0] = nums[0]
        for i in range(1, n):
            p[i] = nums[i] + p[i-1]

        target = sum(nums) / 2
        half = n // 2
        good = 0
        for i in range(n):
            if i == 0 and p[half-1] > target:
                # print(0, i, p[half], target)
                good += 1 
            elif 0 < i <= half and p[i+half-1] - p[i-1] > target:
                # print(1, i, p[i+half-1] - p[i-1] , target)
                good += 1 
            elif i > half and p[i-1] - p[i-1-half] < target:
                # print(2, i, p[i-1] - p[i-1-half], target)
                good += 1 
            # else:
            #     print(i, False)
        return good 


s = Solution()
nums = [1,2,1,2]
nums = [1,2,3,4,5,6]
print(s.countGoodRotations(nums))
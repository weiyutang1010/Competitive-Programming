class Solution:
    def solve(self, nums):
        n = len(nums)
        ans = 1

        for i in range(1, n):
            if nums[i] != nums[i-1]:
                ans += 1

        return ans
        
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_ends = nums[0]
        max_seen_till = nums[0]
        for i in range(1, len(nums)):
            if (max_ends + nums[i] < nums[i]): 
                max_ends = nums[i]
            else:
                max_ends += nums[i]
            if (max_ends > max_seen_till):
                max_seen_till = max_ends
        return max_seen_till
        
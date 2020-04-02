class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr = []
        for num in nums:
          if num not in arr:
            arr.append(num)
          else:
            arr.pop(arr.index(num))
            
        return arr[0]
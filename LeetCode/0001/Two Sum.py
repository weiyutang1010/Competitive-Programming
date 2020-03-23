class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    hashmap = {}
    for i in range(len(nums)):
      search = target - nums[i]
      if search in hashmap:
        return [i, hashmap[search]]
      hashmap[nums[i]] = i
    return []

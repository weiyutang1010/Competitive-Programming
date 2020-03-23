class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min = sys.maxsize
        max_pro = 0

        for i in range(len(prices)):
          if prices[i] < min:
            min = prices[i]
          profit = prices[i] - min
          max_pro = max(max_pro, profit)

        return max_pro

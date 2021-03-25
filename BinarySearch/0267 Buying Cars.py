class Solution:
    def solve(self, prices, k):
        count = 0
        for price in sorted(prices):
            if k >= price:
                k -= price
                count += 1
            else:
                break

        return count
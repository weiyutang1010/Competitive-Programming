class Solution:
    def solve(self, n):
        # dp array for storing intermediate result
        dp = [1, 1]

        # handle base case n = 1, 2
        if n == 1 or n == 2:
            return dp[n - 1]

        # compute result until nth term
        for i in range(2, n):
            dp.append(dp[i - 2] + dp[i - 1])

        # return ans
        return dp[n - 1]

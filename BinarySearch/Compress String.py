class Solution:
    def solve(self, s):
        # initialize useful variables
        n = len(s)
        ans = ""

        # handle edge case
        if n == 0:
            return ans

        # only add character if next character is different to the
        # last character of ans
        for i, char in enumerate(s):
            if i == 0:
                ans += char
            else:
                if char != ans[-1]:
                    ans += char

        # return ans
        return ans
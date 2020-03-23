class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        string = str(x)

        if len(string) <= 1:
          return True
        else:
          return (string[0] == string[-1]) and Solution.isPalindrome(self, string[1:-1])

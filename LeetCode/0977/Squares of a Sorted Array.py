class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        arr = []

        for i in A:
          arr.append(i*i)

        arr.sort()

        return arr

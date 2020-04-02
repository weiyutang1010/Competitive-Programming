class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        array = []
        
        sum = 0
        while True:
          digit_array = [int(i) for i in str(n)]
          for num in digit_array:
            sum += pow(num, 2)
            
          if (sum in array):
            return False
          elif (sum == 1):
            return True
          else:
            array.append(sum)
            n = sum
            sum = 0
            
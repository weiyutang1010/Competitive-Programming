class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        array = []
        if numRows == 1:
          return [[1]]
        elif numRows >= 2:
          array += [[1], [1, 1]]

        print(array)
        for row in range(2, numRows):
          new_array = []
          for col in range(row + 1):
            if(col == 0):
              new_array.append(1)
            elif (col == row):
              new_array.append(1)
            else:
              new_array.append(array[row-1][col-1] + array[row-1][col])
          array.append(new_array)

        return array

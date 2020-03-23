class Solution:
    def reverse(self, x: int) -> int:
      string = str(x)
      new_string = ""

      for i in reversed(range(len(string))):
        if(string[i] == "-"):
          continue
        new_string += string[i]

      y = int(new_string)
      if(string[0] == "-"):
        y *= -1

      if(y >= (2 ** 31)-1) or (y <= -(2 ** 31)):
        return 0

      return y

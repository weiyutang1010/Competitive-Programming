from collections import deque


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        stack = deque()

        for letter in s:
          if (letter == '(' or letter == '{' or letter == '['):
            stack.append(letter)
          elif (len(stack) > 0):
            if (letter == ')' and stack[-1] == '('):
              stack.pop()
            elif (letter == '}' and stack[-1] == '{'):
              stack.pop()
            elif (letter == ']' and stack[-1] == '['):
              stack.pop()
            else:
              return False
          elif (len(stack) == 0):
            return False

        if (len(stack) == 0):
          return True
        else:
          return False

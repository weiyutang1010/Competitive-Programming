# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, target):
        queue = deque()
        queue.append(root)

        while len(queue) > 0:
            node = queue.popleft()
            if node.val == target:
                return True
            elif node.val > target:
                break
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)


        return False
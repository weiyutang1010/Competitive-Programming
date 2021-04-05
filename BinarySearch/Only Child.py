# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node):
        if node.left is None and node.right is None:
            return

        # Look for node with only 1 child
        if node.left is not None and node.right is not None:
            self.dfs(node.left)
            self.dfs(node.right)
        else:
            self.ans += 1
            if node.left is not None:
                self.dfs(node.left)
            elif node.right is not None:
                self.dfs(node.right)

    def solve(self, root):
        self.ans = 0

        if root is not None:
            self.dfs(root)

        return self.ans
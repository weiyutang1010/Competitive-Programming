# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, node):
        if node.left is not None:
            self.inorder(node.left)

        self.ordered_list.append(node.val)

        if node.right is not None:
            self.inorder(node.right)

        return

    def solve(self, root, k):
        self.ordered_list = []
        if root:
            self.inorder(root)
            return self.ordered_list[k]
        return 0
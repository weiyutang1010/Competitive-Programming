# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class LLNode:
#     def __init__(self, val, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def solve(self, root):
        head = LLNode(0)
        if root is not None:
            head = LLNode(root.val)

        queue = deque()
        if root.left is not None:
            queue.append(root.left)
        if root.right is not None:
            queue.append(root.right)
        curr_ll_node = head

        while len(queue) > 0:
            node = queue.popleft()
            curr_ll_node.next = LLNode(node.val)
            curr_ll_node = curr_ll_node.next

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return head
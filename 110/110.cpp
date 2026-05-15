# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root):

        def height(node):

            if not node:
                return 0

            left = height(node.left)

            # cây trái đã mất cân bằng
            if left == -1:
                return -1

            right = height(node.right)

            # cây phải đã mất cân bằng
            if right == -1:
                return -1

            # kiểm tra chênh lệch
            if abs(left - right) > 1:
                return -1

            # trả chiều cao
            return 1 + max(left, right)

        return height(root) != -1
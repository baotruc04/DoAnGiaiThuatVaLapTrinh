# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sortedArrayToBST(self, nums):

        def build(left, right):

            # hết phần tử
            if left > right:
                return None

            # lấy phần tử giữa
            mid = (left + right) // 2

            root = TreeNode(nums[mid])

            # xây cây trái
            root.left = build(left, mid - 1)

            # xây cây phải
            root.right = build(mid + 1, right)

            return root

        return build(0, len(nums) - 1)
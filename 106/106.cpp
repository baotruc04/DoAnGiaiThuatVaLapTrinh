# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder, postorder):
        
        # Lưu vị trí của từng giá trị trong inorder
        index_map = {}

        for i, value in enumerate(inorder):
            index_map[value] = i

        # Dùng biến này để lấy root từ cuối postorder
        self.post_idx = len(postorder) - 1

        def build(left, right):

            # Không còn node
            if left > right:
                return None

            # Lấy root hiện tại
            root_val = postorder[self.post_idx]
            self.post_idx -= 1

            root = TreeNode(root_val)

            # Vị trí root trong inorder
            index = index_map[root_val]

            # Xây cây phải trước
            root.right = build(index + 1, right)

            # Xây cây trái
            root.left = build(left, index - 1)

            return root

        return build(0, len(inorder) - 1)
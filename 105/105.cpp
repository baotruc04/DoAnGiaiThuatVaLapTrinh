class Solution:
    def buildTree(self, preorder, inorder):

        inorder_map = {}

        # Lưu vị trí trong inorder
        for i, val in enumerate(inorder):
            inorder_map[val] = i

        # Dùng list để thay nonlocal
        preorder_index = [0]

        def build(left, right):

            # Không còn node
            if left > right:
                return None

            # Lấy root
            root_val = preorder[preorder_index[0]]
            preorder_index[0] += 1

            root = TreeNode(root_val)

            # Vị trí root trong inorder
            mid = inorder_map[root_val]

            # Build left subtree
            root.left = build(left, mid - 1)

            # Build right subtree
            root.right = build(mid + 1, right)

            return root

        return build(0, len(inorder) - 1)
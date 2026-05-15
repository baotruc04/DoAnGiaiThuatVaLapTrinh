class Solution:
    def recoverTree(self, root):

        self.first = None
        self.second = None
        self.prev = TreeNode(float('-inf'))

        def inorder(node):

            if not node:
                return

            inorder(node.left)

            # Phát hiện lỗi
            if self.prev.val > node.val:

                # Lần đầu gặp lỗi
                if not self.first:
                    self.first = self.prev

                # luôn cập nhật second
                self.second = node

            self.prev = node

            inorder(node.right)

        inorder(root)

        # Swap lại
        self.first.val, self.second.val = (
            self.second.val,
            self.first.val
        )
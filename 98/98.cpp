class Solution:
    def isValidBST(self, root):

        def dfs(node, low, high):

            if not node:
                return True

            # Vi phạm BST
            if not (low < node.val < high):
                return False

            # Left subtree
            left = dfs(node.left, low, node.val)

            # Right subtree
            right = dfs(node.right, node.val, high)

            return left and right

        return dfs(root, float('-inf'), float('inf'))
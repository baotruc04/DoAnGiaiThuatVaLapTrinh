class Solution:
    def generateTrees(self, n):

        if n == 0:
            return []

        def build(left, right):

            # Empty tree
            if left > right:
                return [None]

            trees = []

            # Thử mọi root
            for root_val in range(left, right + 1):

                # Sinh left subtree
                left_trees = build(left, root_val - 1)

                # Sinh right subtree
                right_trees = build(root_val + 1, right)

                # Ghép tất cả combination
                for l in left_trees:
                    for r in right_trees:

                        root = TreeNode(root_val)

                        root.left = l
                        root.right = r

                        trees.append(root)

            return trees

        return build(1, n)
class Solution:
    def isSymmetric(self, root):

        def mirror(left, right):

            # Cả hai rỗng
            if not left and not right:
                return True

            # Một rỗng một không
            if not left or not right:
                return False

            # Giá trị khác nhau
            if left.val != right.val:
                return False

            return (
                mirror(left.left, right.right)
                and
                mirror(left.right, right.left)
            )

        return mirror(root.left, root.right)
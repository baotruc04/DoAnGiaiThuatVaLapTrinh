from collections import deque

class Solution:
    def zigzagLevelOrder(self, root):

        if not root:
            return []

        result = []

        queue = deque([root])

        left_to_right = True

        while queue:

            level = []

            size = len(queue)

            # Duyệt 1 level
            for _ in range(size):

                node = queue.popleft()

                level.append(node.val)

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            # Nếu cần đảo chiều
            if not left_to_right:
                level.reverse()

            result.append(level)

            # Đổi hướng
            left_to_right = not left_to_right

        return result
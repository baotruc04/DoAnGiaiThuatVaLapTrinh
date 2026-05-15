class Solution:
    def deleteDuplicates(self, head):
        current = head

        while current and current.next:

            # Nếu bị trùng
            if current.val == current.next.val:
                current.next = current.next.next

            else:
                current = current.next

        return head
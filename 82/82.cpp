class Solution:
    def deleteDuplicates(self, head):
        # Node giả
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy

        while head:

            # Nếu phát hiện duplicate
            if head.next and head.val == head.next.val:

                # Bỏ qua tất cả node trùng
                while head.next and head.val == head.next.val:
                    head = head.next

                # Nối prev với node tiếp theo
                prev.next = head.next

            else:
                # Không trùng -> giữ lại
                prev = prev.next

            head = head.next

        return dummy.next
class Solution:
    def reverseBetween(self, head, left, right):

        if not head or left == right:
            return head

        # Dummy node
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy

        # Đi tới node trước left
        for _ in range(left - 1):
            prev = prev.next

        # current là node bắt đầu reverse
        current = prev.next

        # Reverse đoạn
        for _ in range(right - left):

            temp = current.next

            current.next = temp.next

            temp.next = prev.next

            prev.next = temp

        return dummy.next
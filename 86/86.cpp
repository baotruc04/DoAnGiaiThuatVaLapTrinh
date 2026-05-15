class Solution:
    def partition(self, head, x):

        # Dummy cho danh sách nhỏ
        small_dummy = ListNode(0)
        small = small_dummy

        # Dummy cho danh sách lớn
        large_dummy = ListNode(0)
        large = large_dummy

        while head:

            if head.val < x:
                small.next = head
                small = small.next
            else:
                large.next = head
                large = large.next

            head = head.next

        # Kết thúc danh sách lớn
        large.next = None

        # Nối 2 danh sách
        small.next = large_dummy.next

        return small_dummy.next
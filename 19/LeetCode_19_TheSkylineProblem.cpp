# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head
        
        fast = dummy
        slow = dummy
        
        # Di chuyển fast trước n+1 bước
        for _ in range(n + 1):
            fast = fast.next
        
        # Di chuyển cả hai đến khi fast chạm cuối
        while fast:
            fast = fast.next
            slow = slow.next
        
        # Xóa node
        slow.next = slow.next.next
        
        return dummy.next

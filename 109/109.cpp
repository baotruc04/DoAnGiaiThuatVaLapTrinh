# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sortedListToBST(self, head):

        # chuyển linked list đoạn [head -> tail)
        def build(head, tail):

            if head == tail:
                return None

            slow = head
            fast = head

            # tìm middle node
            while fast != tail and fast.next != tail:
                slow = slow.next
                fast = fast.next.next

            # slow là middle
            root = TreeNode(slow.val)

            # cây trái
            root.left = build(head, slow)

            # cây phải
            root.right = build(slow.next, tail)

            return root

        return build(head, None)
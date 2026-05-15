class Solution:
    def rotateRight(self, head, k):
        if not head or not head.next or k == 0:
            return head

        # 1. Tính độ dài
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1

        # 2. Tạo vòng tròn
        tail.next = head

        # 3. Tính số bước cần đi
        k = k % length
        steps = length - k

        # 4. Tìm node mới
        new_tail = head
        for _ in range(steps - 1):
            new_tail = new_tail.next

        new_head = new_tail.next

        # 5. Cắt vòng
        new_tail.next = None

        return new_head
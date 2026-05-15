import heapq

class Solution:
    def mergeKLists(self, lists):
        heap = []
        
        # Đưa node đầu mỗi list vào heap
        for i in range(len(lists)):
            aif lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
        
        dummy = ListNode(0)
        current = dummy
        
        while heap:
            val, i, node = heapq.heappop(heap)
            current.next = node
            current = current.next
            
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))
        
        return dummy.next

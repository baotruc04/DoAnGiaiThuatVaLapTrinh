class Solution:
    def getPermutation(self, n, k):
        import math
        
        nums = [str(i) for i in range(1, n + 1)]
        k -= 1  # chuyển về index 0
        
        result = ""
        
        for i in range(n, 0, -1):
            fact = math.factorial(i - 1)
            index = k // fact
            
            result += nums[index]
            nums.pop(index)
            
            k %= fact
        
        return result
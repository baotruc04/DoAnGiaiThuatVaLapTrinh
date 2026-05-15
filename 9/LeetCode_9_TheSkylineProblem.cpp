class Solution:
    def isPalindrome(self, x):
        # Số âm chắc chắn không đối xứng
        if x < 0:
            return False
        
        s = str(x)
        return s == s[::-1]

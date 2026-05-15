class Solution:
    def lengthOfLastWord(self, s):
        s = s.strip()              # xóa khoảng trắng đầu/cuối
        length = 0
        
        i = len(s) - 1
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1
        
        return length
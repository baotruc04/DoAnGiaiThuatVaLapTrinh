class Solution:
    def isNumber(self, s):
        s = s.strip()
        
        num = False     # đã gặp số
        dot = False     # đã gặp .
        exp = False     # đã gặp e/E
        
        for i, c in enumerate(s):
            if c.isdigit():
                num = True
                
            elif c in ['+', '-']:
                # chỉ hợp lệ ở đầu hoặc sau e/E
                if i > 0 and s[i-1] not in ['e', 'E']:
                    return False
                
            elif c == '.':
                # chỉ 1 lần và trước e
                if dot or exp:
                    return False
                dot = True
                
            elif c in ['e', 'E']:
                # chỉ 1 lần và phải có số trước
                if exp or not num:
                    return False
                exp = True
                num = False   # reset để kiểm tra phần sau e
                
            else:
                return False
        
        return num
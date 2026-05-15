class Solution:
    def fullJustify(self, words, maxWidth):
        res = []
        cur = []
        num_of_letters = 0
        
        for w in words:
            # nếu thêm từ mới vượt maxWidth
            if num_of_letters + len(w) + len(cur) > maxWidth:
                # tính khoảng trắng
                spaces = maxWidth - num_of_letters
                
                if len(cur) == 1:
                    # chỉ 1 từ → căn trái
                    res.append(cur[0] + ' ' * spaces)
                else:
                    space_between = spaces // (len(cur) - 1)
                    extra = spaces % (len(cur) - 1)
                    
                    line = ""
                    for i in range(len(cur) - 1):
                        line += cur[i]
                        line += ' ' * (space_between + (1 if i < extra else 0))
                    line += cur[-1]
                    
                    res.append(line)
                
                cur = []
                num_of_letters = 0
            
            cur.append(w)
            num_of_letters += len(w)
        
        # xử lý dòng cuối
        last_line = ' '.join(cur)
        last_line += ' ' * (maxWidth - len(last_line))
        res.append(last_line)
        
        return res
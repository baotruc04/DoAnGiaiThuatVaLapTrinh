class Solution:
    def totalNQueens(self, n):
        col = set()
        diag1 = set()
        diag2 = set()
        
        def backtrack(row):
            if row == n:
                return 1
            
            count = 0
            for c in range(n):
                if c in col or (row - c) in diag1 or (row + c) in diag2:
                    continue
                
                col.add(c)
                diag1.add(row - c)
                diag2.add(row + c)
                
                count += backtrack(row + 1)
                
                col.remove(c)
                diag1.remove(row - c)
                diag2.remove(row + c)
            
            return count
        
        return backtrack(0)
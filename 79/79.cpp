class Solution:
    def exist(self, board, word):
        rows, cols = len(board), len(board[0])

        def dfs(r, c, i):
            # đã match hết word
            if i == len(word):
                return True

            # out of bounds hoặc sai ký tự
            if (r < 0 or c < 0 or r >= rows or c >= cols
                or board[r][c] != word[i]):
                return False

            # đánh dấu đã dùng
            temp = board[r][c]
            board[r][c] = "#"

            # đi 4 hướng
            found = (
                dfs(r+1, c, i+1) or
                dfs(r-1, c, i+1) or
                dfs(r, c+1, i+1) or
                dfs(r, c-1, i+1)
            )

            # backtrack
            board[r][c] = temp

            return found

        # thử từ mọi ô
        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True

        return False
class Solution:
    def convert(self, s, numRows):
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [""] * numRows
        cur_row = 0
        direction = -1   # -1: lên, 1: xuống

        for ch in s:
            rows[cur_row] += ch

            # đổi hướng khi chạm đỉnh hoặc đáy
            if cur_row == 0 or cur_row == numRows - 1:
                direction *= -1

            cur_row += direction

        return "".join(rows)

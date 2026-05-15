class Solution:
    def solveSudoku(self, board):
        
        def isValid(row, col, num):
            # kiểm tra hàng
            for i in range(9):
                if board[row][i] == num:
                    return False

            # kiểm tra cột
            for i in range(9):
                if board[i][col] == num:
                    return False

            # kiểm tra ô 3x3
            startRow = (row // 3) * 3
            startCol = (col // 3) * 3

            for i in range(3):
                for j in range(3):
                    if board[startRow + i][startCol + j] == num:
                        return False

            return True

        def backtrack():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == ".":

                        for num in "123456789":
                            if isValid(i, j, num):
                                board[i][j] = num

                                if backtrack():
                                    return True

                                board[i][j] = "."  # quay lui

                        return False
            return True

        backtrack()
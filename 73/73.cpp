class Solution:
    def setZeroes(self, matrix):

        rows = set()
        cols = set()

        m = len(matrix)
        n = len(matrix[0])

        # Tìm các vị trí có số 0
        for i in range(m):
            for j in range(n):

                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)

        # Đổi hàng thành 0
        for i in rows:
            for j in range(n):
                matrix[i][j] = 0

        # Đổi cột thành 0
        for j in cols:
            for i in range(m):
                matrix[i][j] = 0
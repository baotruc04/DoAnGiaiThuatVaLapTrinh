class Solution:
    def maximalRectangle(self, matrix):

        if not matrix:
            return 0

        cols = len(matrix[0])
        heights = [0] * cols

        max_area = 0

        for row in matrix:

            # Build histogram
            for i in range(cols):

                if row[i] == "1":
                    heights[i] += 1
                else:
                    heights[i] = 0

            # Tính largest rectangle của histogram
            max_area = max(max_area, self.largestRectangleArea(heights))

        return max_area


    def largestRectangleArea(self, heights):

        stack = []
        max_area = 0

        heights.append(0)

        for i in range(len(heights)):

            while stack and heights[i] < heights[stack[-1]]:

                h = heights[stack.pop()]

                if stack:
                    width = i - stack[-1] - 1
                else:
                    width = i

                max_area = max(max_area, h * width)

            stack.append(i)

        heights.pop()

        return max_area
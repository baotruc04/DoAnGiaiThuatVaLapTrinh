class Solution:
    def largestRectangleArea(self, heights):
        stack = []
        max_area = 0

        # thêm cột 0 cuối mảng để xử lý hết stack
        heights.append(0)

        for i in range(len(heights)):

            # Nếu cột hiện tại thấp hơn stack top
            while stack and heights[i] < heights[stack[-1]]:

                h = heights[stack.pop()]

                # Tính width
                if stack:
                    width = i - stack[-1] - 1
                else:
                    width = i

                max_area = max(max_area, h * width)

            stack.append(i)

        return max_area
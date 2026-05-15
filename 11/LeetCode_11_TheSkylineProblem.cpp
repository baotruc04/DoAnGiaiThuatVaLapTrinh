class Solution:
    def maxArea(self, height):
        left = 0
        right = len(height) - 1
        max_water = 0
        
        while left < right:
            h = min(height[left], height[right])
            width = right - left
            max_water = max(max_water, h * width)
            
            # Di chuyển con trỏ ở cột thấp hơn
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return max_water

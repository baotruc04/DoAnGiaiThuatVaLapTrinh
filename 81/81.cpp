class Solution:
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            # Tìm thấy target
            if nums[mid] == target:
                return True

            # Không xác định được bên nào sorted
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1

            # Nửa bên trái đã sorted
            elif nums[left] <= nums[mid]:
                # target nằm trong nửa trái
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            # Nửa bên phải đã sorted
            else:
                # target nằm trong nửa phải
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return False
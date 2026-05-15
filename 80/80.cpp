class Solution:
    def removeDuplicates(self, nums):
        i = 0

        for num in nums:
            # Giữ tối đa 2 phần tử giống nhau
            if i < 2 or num != nums[i - 2]:
                nums[i] = num
                i += 1

        return i
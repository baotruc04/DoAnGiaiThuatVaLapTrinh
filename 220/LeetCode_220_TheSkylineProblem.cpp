class Solution:
    def containsNearbyAlmostDuplicate(self, nums, indexDiff, valueDiff):
        if valueDiff < 0:
            return False

        buckets = {}
        size = valueDiff + 1  # kích thước mỗi bucket

        for i, num in enumerate(nums):
            bucket_id = num // size

            # 1. Cùng bucket
            if bucket_id in buckets:
                return True

            # 2. Bucket bên trái
            if bucket_id - 1 in buckets and abs(num - buckets[bucket_id - 1]) <= valueDiff:
                return True

            # 3. Bucket bên phải
            if bucket_id + 1 in buckets and abs(num - buckets[bucket_id + 1]) <= valueDiff:
                return True

            # Thêm vào bucket
            buckets[bucket_id] = num

            # Giữ cửa sổ indexDiff
            if i >= indexDiff:
                old_bucket = nums[i - indexDiff] // size
                del buckets[old_bucket]

        return False

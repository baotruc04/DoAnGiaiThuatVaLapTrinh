class Solution:
    def reverse(self, x):
        INT_MAX = 2147483647
        INT_MIN = -2147483648

        res = 0
        sign = 1

        if x < 0:
            sign = -1
            x = -x

        while x != 0:
            digit = x % 10
            x //= 10

            # kiểm tra tràn
            if res > INT_MAX // 10 or (res == INT_MAX // 10 and digit > 7):
                return 0

            res = res * 10 + digit

        return sign * res

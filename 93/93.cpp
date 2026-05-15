class Solution:
    def restoreIpAddresses(self, s):

        result = []

        def backtrack(start, path):

            # Đủ 4 phần
            if len(path) == 4:

                # Dùng hết chuỗi
                if start == len(s):
                    result.append(".".join(path))

                return

            # Thử lấy 1 -> 3 chữ số
            for length in range(1, 4):

                if start + length > len(s):
                    break

                part = s[start:start + length]

                # Leading zero
                if len(part) > 1 and part[0] == '0':
                    continue

                # > 255
                if int(part) > 255:
                    continue

                path.append(part)

                backtrack(start + length, path)

                path.pop()

        backtrack(0, [])

        return result
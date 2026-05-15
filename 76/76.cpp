from collections import Counter

class Solution:
    def minWindow(self, s, t):

        if not s or not t:
            return ""

        need = Counter(t)
        window = {}

        have = 0
        need_count = len(need)

        left = 0

        res = [-1, -1]
        res_len = float("inf")

        for right in range(len(s)):

            char = s[right]

            window[char] = window.get(char, 0) + 1

            if char in need and window[char] == need[char]:
                have += 1

            # Khi cửa sổ hợp lệ
            while have == need_count:

                # cập nhật kết quả
                if (right - left + 1) < res_len:

                    res = [left, right]
                    res_len = right - left + 1

                # thu nhỏ cửa sổ
                window[s[left]] -= 1

                if s[left] in need and window[s[left]] < need[s[left]]:
                    have -= 1

                left += 1

        left, right = res

        return s[left:right + 1] if res_len != float("inf") else ""
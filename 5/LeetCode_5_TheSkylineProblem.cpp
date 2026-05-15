class Solution:
    def longestPalindrome(self, s):
        if len(s) <= 1:
            return s

        res = ""

        def expand(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]

        for i in range(len(s)):
            # palindrome lẻ
            p1 = expand(i, i)
            # palindrome chẵn
            p2 = expand(i, i + 1)

            if len(p1) > len(res):
                res = p1
            if len(p2) > len(res):
                res = p2

        return res

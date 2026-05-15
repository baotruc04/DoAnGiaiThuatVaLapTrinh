from functools import lru_cache

class Solution:
    def isScramble(self, s1, s2):

        @lru_cache(None)
        def dfs(a, b):

            # Nếu giống nhau
            if a == b:
                return True

            # Nếu khác ký tự
            if sorted(a) != sorted(b):
                return False

            n = len(a)

            # Thử mọi cách chia
            for i in range(1, n):

                # Không swap
                if dfs(a[:i], b[:i]) and dfs(a[i:], b[i:]):
                    return True

                # Có swap
                if dfs(a[:i], b[n-i:]) and dfs(a[i:], b[:n-i]):
                    return True

            return False

        return dfs(s1, s2)
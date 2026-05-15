class Solution:
    def numDecodings(self, s):

        n = len(s)

        dp = [0] * (n + 1)

        # Base case
        dp[n] = 1

        # Duyệt ngược
        for i in range(n - 1, -1, -1):

            # Không decode được nếu là 0
            if s[i] == '0':
                dp[i] = 0

            else:
                # Lấy 1 chữ số
                dp[i] = dp[i + 1]

                # Lấy 2 chữ số
                if (i + 1 < n and
                    10 <= int(s[i:i+2]) <= 26):

                    dp[i] += dp[i + 2]

        return dp[0]
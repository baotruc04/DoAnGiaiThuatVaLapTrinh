class Solution:
    def isInterleave(self, s1, s2, s3):

        # Độ dài không khớp
        if len(s1) + len(s2) != len(s3):
            return False

        m = len(s1)
        n = len(s2)

        dp = [[False] * (n + 1) for _ in range(m + 1)]

        dp[0][0] = True

        # Chỉ dùng s1
        for i in range(1, m + 1):
            dp[i][0] = (
                dp[i - 1][0]
                and s1[i - 1] == s3[i - 1]
            )

        # Chỉ dùng s2
        for j in range(1, n + 1):
            dp[0][j] = (
                dp[0][j - 1]
                and s2[j - 1] == s3[j - 1]
            )

        # Fill DP
        for i in range(1, m + 1):
            for j in range(1, n + 1):

                dp[i][j] = (
                    (dp[i - 1][j] and
                     s1[i - 1] == s3[i + j - 1])

                    or

                    (dp[i][j - 1] and
                     s2[j - 1] == s3[i + j - 1])
                )

        return dp[m][n]
class Solution:
    def multiply(self, num1, num2):

        if num1 == "0" or num2 == "0":
            return "0"

        m = len(num1)
        n = len(num2)

        result = [0] * (m + n)

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                mul = int(num1[i]) * int(num2[j])
                sum_val = mul + result[i + j + 1]

                result[i + j + 1] = sum_val % 10
                result[i + j] += sum_val // 10

        res = ""

        for num in result:
            if not (len(res) == 0 and num == 0):
                res += str(num)

        return res
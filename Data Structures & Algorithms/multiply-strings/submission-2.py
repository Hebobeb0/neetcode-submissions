class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1=='0' or num2=='0':
            return '0'
        n=len(num1)
        m = len(num2)
        res = 0
        for i in range(n):
            for j in range(m):
                inc = (ord(num1[n-1-i])-ord('0'))*(ord(num2[m-1-j])-ord('0'))*pow(10,i+j)
                res+= inc
        return str(res)
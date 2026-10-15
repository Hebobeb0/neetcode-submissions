from functools import cache
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or (s and s[0]=="0"):
            return 0
        @cache
        def dp(c):
            if not c:
                return 1
            if len(c)==1:
                return 1
            long, short = c[-2]+c[-1], c[-1]
            if (long[0]=='0' or int(long)>26) and short=='0':
                
                return 0
            if len(c) ==2 and int(c)>26:
                return 1
            res = 0
            if long[0]!='0' and int(long)<=26:
                res+=dp(c[:-2])
            if short!='0':
                res+=dp(c[:-1])
            return res
        return dp(s)
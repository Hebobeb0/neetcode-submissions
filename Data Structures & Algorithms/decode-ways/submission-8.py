from functools import cache
class Solution:
    def numDecodings(self, s: str) -> int:
        @cache
        def dp(c):
            if not c:
                return 1
            if len(c)==1:
                if c=='0':
                    return 0
                else:
                    return 1
            s,l = c[-1], c[-2]+c[-1]
            if (l[0]=='0' or int(l)>26) and s=='0':
                return 0
            if len(c)==2 and int(c)>26:
                return 1
            res = 0
            if l[0]!='0' and int(l)<=26:
                res+=dp(c[:-2])
            if s!='0':
                res+=dp(c[:-1])
            return res
        return dp(s)
from functools import cache
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        @cache
        def dp(s1,s2):
            res = 0
            while (s1 and s2) and s1[0]==s2[0]:
                res+=1
                s1= s1[1:]
                s2=s2[1:]
            if not s1 or not s2:
                return res
            return res + max(dp(s1[1:], s2), dp(s1,s2[1:]))
        return dp(text1,text2)
from functools import cache
class Solution:
    @cache
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if not s1:
            return s2==s3
        if not s2:
            return s1==s3
        if not s3:
            return not s1 or not s2
        a,b,c = s1[0],s2[0],s3[0]
        if a==b and a!=c:
            return False
        res = False
        if a==c:
            res = self.isInterleave(s1[1:], s2 ,s3[1:])
        if b==c:
            res =self.isInterleave(s1, s2[1:],s3[1:]) or res
        return res

from functools import cache

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n,m,o = len(s1),len(s2),len(s3)
        if n+m!=o:
            return False
        @cache
        def dp(i,j):
            k = i+j
            if i==n and j==m:
                return k==o
            if i==n:
                return (dp(i,j+1) if s2[j]==s3[k] else False)
            if j==m:
                return (dp(i+1,j) if s1[i]==s3[k]else False)
            if k==o:
                return i==n and j==m
            res = False
            if s1[i]==s3[k]:
                res = res or dp(i+1,j)
            if s2[j]==s3[k]:
                res= res or dp(i,j+1)
            return res
        return dp(0,0)
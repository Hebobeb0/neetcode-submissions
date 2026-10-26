from functools import cache
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
      n = len(s)
      p = len(t)
      @cache
      def dp(Spos, Tpos):
        if Tpos==p:
          return 1
        if Spos>=n or Tpos>=p:
          return 0
        res = dp(Spos+1,Tpos)
        if s[Spos] == t[Tpos]:
          res += dp(Spos+1, Tpos+1)
        return res
      return dp(0,0)
          
          
          
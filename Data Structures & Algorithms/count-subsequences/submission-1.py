from functools import cache
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
      n = len(s)
      p = len(t)
      @cache
      def dp(pos, curr):
        m = len(curr)
        if curr==t:
          return 1
        if pos>=n or m>p:
          return 0
        res = dp(pos+1,curr)
        if s[pos] == t[m]:
          res += dp(pos+1, curr+s[pos])
        return res
      return dp(0,"")
          
          
          
from functools import cache
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums.insert(0,1)
        nums.append(1)
        mytuple = tuple(nums)
        @cache
        def dp(curr):
          if len(curr)==2:
            return 0
          res = 0
          for i in range(1,len(curr)-1):
            res = max(res,dp(curr[:i]+curr[i+1:])+(curr[i-1]*curr[i]*curr[i+1]))
          return res
        return dp(mytuple)
          
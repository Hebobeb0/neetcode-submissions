from functools import cache

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n= len(nums)
        @cache
        def dp(s,i):
            if i==n:
                return 1 if s==target else 0
            return dp(s+nums[i], i+1) + dp(s-nums[i],i+1)
        return dp(0,0)
                
                
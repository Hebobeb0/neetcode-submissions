from functools import cache
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        @cache
        def dp(curr,i):
            if curr == 0:
                return 1
            if curr<0 or i==n:
                return 0
            return dp(curr-coins[i],i)+dp(curr, i+1)
        return dp(amount,0)
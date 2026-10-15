from functools import cache
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        @cache
        def dp(curr,i):
            if curr == 0:
                return 1
            if curr<0:
                return 0
            return dp(curr-coins[i],i)+(dp(curr, i+1) if i+1<n else 0)
        return dp(amount,0)
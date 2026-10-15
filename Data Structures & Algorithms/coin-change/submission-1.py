class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0]*(amount+1)
        coins.sort()
        dp[0]=1
        for i in range(amount+1):
            for coin in coins:
                if dp[i] and i+coin<=amount:
                    if dp[i+coin]:
                        dp[i+coin] = min(dp[i+coin], dp[i]+1)
                    else:
                        dp[i+coin] = dp[i]+1
        return dp[amount]-1
                
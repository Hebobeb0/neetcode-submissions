class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        k = sum(nums)
        if k%2:
            return False
        if k ==0:
            return True
        k //=2 
        print(k)
        dp = [0]*(k+1)
        dp[0]=1
        for i in range(len(nums)):
            curr = nums[i]
            for j in range(len(dp)-1,-1,-1):
                
                if dp[j]>0 and j+curr<=k:
                    dp[j+curr]=1
                if dp[k]:
                    return True
        return False
        
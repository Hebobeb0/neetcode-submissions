class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        output =[]
        n = len(nums)
        if n<=k:
            return [max(nums)]
        currmax = max(nums[0:k])
        output.append(currmax)
        L,R=0,k-1
        while(R+1<n):
            R+=1
            if nums[R]>currmax:
                currmax = nums[R]
                L=R
            if R-L+1 > k:
                L+=1
                currmax = max(nums[L:R+1])
            output.append(currmax)
        return output

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        p1,p2 = [ 0 for _ in range(n)], [0 for _ in range(n)]
        p1[0] = nums[0]
        p2[-1] = nums[-1]
        
        for i in range(1,n):
            p1[i] = p1[i-1]*nums[i]
        for i in range(n-2,-1,-1):
            p2[i] = p2[i+1]*nums[i]
        output = [0 for _ in range(n)]
        output[n-1] = p1[n-2]
        output[0] = p2[1]
        for i in range(1,n-1):
            output[i] = p1[i-1]*p2[i+1]
        return output
        
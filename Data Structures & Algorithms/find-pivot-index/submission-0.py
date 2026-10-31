class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        cumleft = [0]*n
        cumleft[0] = nums[0]
        for i in range(1,len(nums)):
            cumleft[i] = nums[i]+ cumleft[i-1]
        for i in range(len(nums)):
            if cumleft[i]-nums[i] == cumleft[-1]-cumleft[i]:
                return i
        return -1
from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def cmp(a,b):
            return int(str(b)+str(a)) - int(str(a)+str(b))
        nums.sort(key=cmp_to_key(cmp))
        res=""
        if nums[0]==0:
            return '0'
        for num in nums:
            res+=str(num)
        return res
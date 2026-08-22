class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        myset = set()
        if len(nums)<2:
            return len(nums)

        for n in nums:
            myset.add(n)
        maxc = 1
        temp = 1
        for n in myset:
            temp=1
            if not n-1 in myset:
                temp=1
                k=1
                while n+k in myset:
                    temp+=1
                    k+=1
            maxc = max(maxc, temp)
        return maxc
            
            
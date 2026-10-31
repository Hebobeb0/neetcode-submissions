class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_nums = [(nums[i],i) for i in range(len(nums))]
        sorted_nums.sort(key=lambda a: (a[0],a[1]))
        n = len(nums)
        l = 0
        r = 1
        for l in range(n-1):
            curr = sorted_nums[l][0]+sorted_nums[r][0]
            if curr<target:
                while(curr<target and r<n-1):
                    r+=1
                    curr = sorted_nums[l][0]+sorted_nums[r][0]
            else:
                while(curr>target and r>l+1):
                    r-=1
                    curr=sorted_nums[l][0]+sorted_nums[r][0]
            if curr == target:
                return [min(sorted_nums[l][1],sorted_nums[r][1]),max(sorted_nums[l][1],sorted_nums[r][1])]
            else:
                l+=1
            
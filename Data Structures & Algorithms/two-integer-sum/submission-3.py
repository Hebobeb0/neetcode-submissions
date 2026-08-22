class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = len(nums)
        numsdict = {}
        for n in nums:
            if n in numsdict:
                numsdict[n]+=1
            else:
                numsdict[n]=1
        residue = 0
        n = 0
        found = False
        for n in numsdict.keys():
            residue = target - n
            if residue in numsdict:
                if residue == n:
                    if numsdict[residue]>1:
                        found = True
                        break
                else:
                    found = True 
            if found:
                break
        temp =n
        print(temp,residue)
        if residue == temp:
            result = []
            for n in range(m):
                if nums[n]==residue:
                    result.append(n)
            return result
        i1,i2 = -1,-1
        for n in range(m):
            if nums[n]==temp:
                i1=n
            elif nums[n]==residue:
                i2 = n
        return [min(i1,i2),max(i1,i2)]
                
        
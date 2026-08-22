class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ndict = dict()
        n = len(nums)
        for i in range(n):
            m = nums[i]
            if m in ndict:
                ndict[m]+= 1
            else:
                ndict[m]=1
        mink = -1
        minindex = 0
        result = [-1 for _ in range(k)]
        freq = [-1 for _ in range(k)]
        print(ndict)
        for m in ndict.keys():
            if ndict[m]>mink:
                result[minindex] = m
                freq[minindex] = ndict[m]
                mink = min(freq)
                for i in range(k):
                    if freq[i]==mink:
                        minindex = i
                        break
        return result
            
        
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        res = 0
        target = k*threshold
        n=len(arr)
        curr = sum(arr[:k])
        if curr>=target:
            res+=1
        for i in range(1,n-k+1):
            curr+=arr[i+k-1]-arr[i-1]
            if curr>=target:
                res+=1
        return res

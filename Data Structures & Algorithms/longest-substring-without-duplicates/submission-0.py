class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s)==1:
            return 1
        res=1
        letters=set()
        l,r=0,0
        letters.add(s[0])
        n=len(s)
        while r<n-1:
            r+=1
            while s[r] in letters:
                letters.remove(s[l])
                l+=1
            letters.add(s[r])
            res = max(res,r-l+1)
        return max(res,r-l+1)
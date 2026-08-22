class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        if n<=k+1:
            return min(n,k+1)
        ccount = dict()
        for i in range(26):
            ccount[chr(ord("A")+i)] = 0
        L,R = 0,0
        print(ccount)
        ccount[s[L]]=1+ccount[s[L]]
        maxc = 1
        window = R-L+1
        maxlen = 1
        while R<n-1:
            window = R-L+1
            R+=1
            ccount[s[R]]+=1
            maxc = max(ccount.values())
            window = R-L+1
            while window-maxc>k:
                ccount[s[L]]-=1
                L+=1
                maxc = max(ccount.values())
                window = R-L+1
            window = R-L+1
            maxlen = max(maxlen,window)
        return maxlen
                
    


        
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        d=dict()
        def c():
            for _,b in d.items():
                if b<0:
                    return False
            return True
        for s in s1:
            if not s in d:
                d[s]=0
            d[s]-=1
        n,m = len(s1),len(s2)
        if n>m:
            return False
        for j in range(n):
            if s2[j] in d:
                d[s2[j]]+=1
        if c():
            return True
        for i in range(1,m-n+1):
            if s2[i-1] in d:
                d[s2[i-1]]-=1
            if s2[i+n-1] in d:
                d[s2[i+n-1]]+=1
            if c():
                return True
        return False
            
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n,m = len(s),len(t)
        sset,tset = dict(),dict()
        for i in range(26):
            c = chr(ord("a")+i)
            sset[c]=0
            tset[c]=0
        if n!=m:
            return False
        for i in range(n):
            sset[s[i]]+=1
            tset[t[i]]+=1
        for i in range(26):
            c = chr(ord("a")+i)
            if sset[c]!=tset[c]:
                return False
        return True
            
        
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = dict()
        for st in s:
            if not st in d:
                d[st] = 0
            d[st] +=1
        for st in t:
            if st not in d:
                return False
            d[st]-= 1
            if d[st]<0:
                return False
        for a,b in d.items():
            if b!=0:
                return False
        return True
        
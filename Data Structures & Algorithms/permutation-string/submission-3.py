class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n,m = len(s1),len(s2)
        if n>m:
            return False
        if m ==1:
            return s1==s2
        checklist = dict()
        mvcount = dict()
        for i in range(26):
            c = chr(ord("a") + i)
            checklist[c]= 0
            mvcount[c]=0
        for c in s1:
            checklist[c]+=1
        #print("checklist: ",checklist)
        for i in range(n):
            mvcount[s2[i]]+=1
        found = True
        for i in range(26):
            c = chr(ord("a") + i)
            if checklist[c]!=mvcount[c]:
                found = False
        if found:
            return True
        for i in range(1,m-n+1):
            mvcount[s2[i-1]]-=1
            mvcount[s2[i+n-1]]+=1
            print(mvcount)
            found = True
            for i in range(26):
                c = chr(ord("a") + i)
                if checklist[c]!=mvcount[c]:
                    found = False
            if found:
                return True
        return False
            
        
        
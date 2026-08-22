class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n,m = len(s),len(t)
        if n<m:
            return ""
        if n==1:
            if s==t:
                return s
        s_ct,t_ct=dict(),dict()
        for a in ["A","a"]:
            for i in range(26):
                c= chr(ord(a)+i)
                s_ct[c] = 0
                t_ct[c] = 0
        for c in t:
            t_ct[c]+=1
        L,R = 0,0
        s_ct[s[0]]+=1
        currans = ""
        bestlen = 10000
        same = True
        for a in ["A","a"]:
            for i in range(26):
                c= chr(ord(a)+i)
                if s_ct[c]<t_ct[c]:
                    same = False
                    break
            if same == False:
                break
        if same:
            if (R-L+1<bestlen):
                currans = s[L:R+1]
                #print(currans)
                bestlen = R-L+1
        while R<n-1:
            R+=1
            s_ct[s[R]]+=1
            cont = True
            while(cont and L<R):
                cont = False
                if s_ct[s[L]]>t_ct[s[L]]:
                    s_ct[s[L]]-=1
                    L+=1
                    cont = True
            same = True
            for a in ["A","a"]:
                for i in range(26):
                    c= chr(ord(a)+i)
                    if s_ct[c]<t_ct[c]:
                        same = False
                        break
                if same == False:
                    break
            if same:
                if (R-L+1<bestlen):
                    currans = s[L:R+1]
                    #print(currans)
                    bestlen = R-L+1
        return currans
                    
                    
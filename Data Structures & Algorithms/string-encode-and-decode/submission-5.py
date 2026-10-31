class Solution:

    def encode(self, strs: List[str]) -> str:
        running = 0
        pad = ['0']
        for s in strs:
            running+=len(s)
            pad.append(str(running))
        k = len(pad)
        res = str(k) + ";"
        res+= ';'.join(pad)
        res+=';'
        res+=''.join(strs)
        return res
    
        
        
    def decode(self, s: str) -> List[str]:
        res = []
        temp = s.split(';')
        n = int(temp[0])
        temp2 = ';'.join(temp[:n+1])
        temp2 += ';'
        l = len(temp2)
        cleaned = s[l:]
        for i in range(n-1):
            curr = ""
            a,b= int(temp[i+1]),int(temp[i+2])
            for j in range(a,b):
                curr+=cleaned[j]
            res.append(curr)
        return res

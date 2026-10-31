class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        count = 0
        res+=str(count)+','
        for s in strs:
            count+=len(s)
            res+=str(count)+','
        res = res[:-1]
        res+='#'
        res+=''.join(strs)
        return res
        
    def decode(self, s: str) -> List[str]:
        temp = s.split('#')[0]
        clean = s[len(temp)+1:]
        temp = temp.split(',')
        res = []
        for i in range(len(temp)-1):
            res.append(clean[int(temp[i]):int(temp[i+1])])
        return res
        

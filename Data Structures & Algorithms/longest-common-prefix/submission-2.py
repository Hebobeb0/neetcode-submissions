class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = strs[0]
        for s in strs:
            if len(res)==0:
                return res
            temp = ''
            for i in range(min(len(s),len(res))):
                if s[i]==res[i]:
                    temp +=res[i]
                else:
                    break
            res = temp
        return res
        
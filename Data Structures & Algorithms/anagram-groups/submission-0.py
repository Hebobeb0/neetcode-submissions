class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        n = len(strs)
        p = [dict() for _ in range(n)]
        for i in range(n):
            s = strs[i]
            for j in range(26):
                p[i][chr(ord("a")+j)]=0
            for c in s:
                p[i][c]+=1
        result = []
        checker=[]
        for m in range(n):
            k = len(checker)
            found = False
            for l in range(k):
                equal = True
                for j in range(26):
                    c = chr(ord("a")+j)
                    if checker[l][c] != p[m][c]:
                        equal = False
                        break
                if equal:
                    found = True
                    result[l].append(strs[m])
                    break
            if not found:
                result.append([strs[m]])
                checker.append(p[m])
        return result

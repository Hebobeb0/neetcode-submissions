class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n,m = len(matrix), len(matrix[0])
        mem = [[0]*m for _ in range(n)]
        marked = [[False]*m for _ in range(n)]
        xd = [1,-1,0,0]
        yd = [0,0,1,-1]
        
        def dp(x,y):
            curr = matrix[x][y]
            res = 0
            for i in range(4):
                xt = x+xd[i]
                yt = y+yd[i]
                if xt>=0 and xt<n and yt>=0 and yt<m and not marked[xt][yt] and matrix[xt][yt]>curr:
                    if not mem[xt][yt]:
                        marked[xt][yt]=True
                        mem[xt][yt] = dp(xt,yt)
                        marked[xt][yt]=False
                    res = max(res, mem[xt][yt])
            return res+1
                        
        for i in range(n):
            for j in range(m):
                if not mem[i][j]:
                    mem[i][j]=dp(i,j)
        res = 0
        for i in range(n):
            for j in range(m):
                res = max(res,mem[i][j])
        return res
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        n = len(grid)
        m = len(grid[0])
        def fill(x,y):
            grid[x][y] = res
            xdir = [1,-1,0,0]
            ydir = [0,0,1,-1]
            for i in range(4):
                xtemp = x+xdir[i]
                ytemp = y+ydir[i]
                if xtemp>=0 and xtemp<n and ytemp>=0 and ytemp<m and grid[xtemp][ytemp] == "1":
                    fill(xtemp,ytemp)

        for i in range(n):
            for j in range(m):
                if grid[i][j]=="1":
                    res -= 1
                    fill(i,j)
        return -res
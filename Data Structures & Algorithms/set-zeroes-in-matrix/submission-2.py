class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n,m = len(matrix),len(matrix[0])
        col = set()
        row = set()
        for i in range(n):
            for j in range(m):
                if not matrix[i][j]:
                    row.add(i)
                    col.add(j)
        for i in range(n):
            for j in range(m):
                if i in row or j in col:
                    matrix[i][j]=0
        

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        valid = [True for i in range(n)]
        res = []
        curr = []
        def check():
          m = len(curr)
          for i in range(m-1):
            for j in range(i+1,m):
              a,b = curr[i]
              c,d = curr[j]
              if abs(a-c) == abs(b-d):
                return False
              if a==c or b==d:
                return False
          return True
        def dp(y):
          if y==n:
            res.append(curr.copy())
            return
          for x in range(n):
            if valid[x]:
              valid[x]=False
              curr.append((x,y))
              if check():
                dp(y+1)
              del curr[-1]
              valid[x]=True
        dp(0)
        output = []
        blankline = ""
        for i in range(n):
          blankline+="."
        for item in res:
          board = [blankline]*n
          for x,y in item:
            board[y] = board[y][:x]+"Q"+board[y][x+1:]
          output.append(board)
        return output
        

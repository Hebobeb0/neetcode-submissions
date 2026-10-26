
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        curr = []
        posdiag = set()
        negdiag = set()
        col = set()
        row = set()
        def dp(y):
          if y==n:
            res.append(curr.copy())
            return
          for x in range(n):
            if not x in col and not (x+y) in posdiag and not (x-y) in negdiag:
              col.add(x)
              posdiag.add(x+y)
              negdiag.add(x-y)
              curr.append((x,y))
              dp(y+1)
              curr.pop()
              col.remove(x)
              posdiag.remove(x+y)
              negdiag.remove(x-y)
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
        

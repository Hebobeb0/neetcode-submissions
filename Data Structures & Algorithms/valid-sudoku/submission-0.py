class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        #check 3x3
        for i in range(3):
            for j in range(3):
                count = set()
                for k in range(3):
                    for l in range(3):
                        c=board[i*3+k][j*3+l]
                        if c != ".":
                            if c in count:
                                print("1")
                                return False
                            else:
                                count.add(c)
        #check rows and columns
        for i in range(9):
            count = set()
            count2=set()
            for j in range(9):
                c = board[i][j]
                c2 =board[j][i]
                if c!="." :
                    if c in count:
                        return False
                    else:
                        count.add(c)
                if c2!=".":
                    if c2 in count2:
                        return False
                    else:
                        count2.add(c2)
        return True
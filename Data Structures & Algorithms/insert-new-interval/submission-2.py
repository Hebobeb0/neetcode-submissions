class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        vals = [x for a,b in intervals for x in (a,b)]
        m = len(vals)
        start,end=-1,m
        printstart,printend = True,True
        for i in range(m):
            if vals[i]<newInterval[0]:
                start = i
                if i%2:
                    printstart = True
                else:
                    printstart = False
            if vals[m-i-1]>newInterval[1]:
                end = m-i-1
                if (m-i-1)%2==0:
                    printend= True
                else:
                    printend=False
        newvals = []
        for i in range(0,start+1):
            newvals.append(vals[i])
        if printstart:
            newvals.append(newInterval[0])
        if printend:
            newvals.append(newInterval[1])
        for i in range(end,m):
            newvals.append(vals[i])
        k = len(newvals)
        res = []
        for i in range(0,k,2):
            temp = [newvals[i],newvals[i+1]]
            res.append(temp)
        return res

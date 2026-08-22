class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        t = len(prices)
        pmin = [1000 for n in range(t)]
        pmax = [-1 for n in range(t)]
        pmin[0]=prices[0]
        pmax[t-1]=prices[t-1]
        for i in range(1,t):
            p = prices[i]
            pmin[i]=min(p,pmin[i-1])
        for i in range(t-2,-1,-1):
            p=prices[i]
            pmax[i]=max(p,pmax[i+1])
        print(pmin)
        print(pmax)
    
        
        if t==1:
            return 0
        profit=0

        for i in range(t-1):
            profit = max(profit,pmax[i+1]-pmin[i])
        return profit


        
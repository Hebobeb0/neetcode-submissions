class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        par = [i for i in range(n)]
        rank = [1]*n
        def find(m):
            res = m
            while(res!=par[res]):
                par[res] = par[par[res]]
                res = par[res]
            return res
        def union(x,y):
            p1,p2 = find(x),find(y)
            if p1==p2: 
                return 0
            else:
                if rank[p1]>=rank[p2]:
                    par[p2]=p1
                    rank[p1]+=rank[p2]
                else:
                    par[p1]=p2
                    rank[p2]+=rank[p1]
                return 1
        comp = n
        for edge in edges:
            comp-=union(edge[0],edge[1])
        return comp

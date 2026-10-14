from collections import deque

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        network = [dict([]) for _ in range(n+1)]
        res = [-1]*(n+1)
        for ui,vi,ti in times:
            if vi not in network[ui]:
                network[ui][vi] = ti
            else:
                network[ui][vi] = min(ti, network[ui][vi])
        res[k] = 0
        q = deque([(k, 0)])
        while len(q):
            curr, l = q.popleft()
            for d,length in network[curr].items():
                if res[d]<0 or res[d]>l+length:
                    q.append((d,l+length))
                    res[d] =l+length
        if min(res[1:])==-1:
            return -1
        return max(res)
        
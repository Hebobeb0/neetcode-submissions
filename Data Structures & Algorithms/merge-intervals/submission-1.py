class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda a: a[0])
        m = len(intervals)
        res = []

        start = intervals[0][0]
        end = intervals[0][1]
        for point in range(1,m):
            if intervals[point][0]>end:
                res.append([start,end])
                start = intervals[point][0]
            end = max(end,intervals[point][1])
        res.append([start,end])
        return res
        
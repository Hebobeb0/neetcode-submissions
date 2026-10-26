import heapq
class MedianFinder:

    def __init__(self):
      self.minheap = []
      self.maxheap = []


    def addNum(self, num: int) -> None:
        heapq.heappush(self.minheap,num)
        heapq.heappush(self.maxheap,-heapq.heappop(self.minheap))
        while len(self.minheap)<len(self.maxheap):
          heapq.heappush(self.minheap,-heapq.heappop(self.maxheap))

    def findMedian(self) -> float:
        if len(self.minheap)==len(self.maxheap):
          return (self.minheap[0]-self.maxheap[0])/2
        return self.minheap[0]
        
class unionfind:
  def __init__(self,size):
    self.par = [i for i in range(size)]
    self.rank = [1]*size
  def find(self,i):
    if self.par[i] == i:
      return i
    self.par[i] = self.find(self.par[i])
    return self.par[i]
  def union(self,a,b):
    root_a,root_b = self.find(a),self.find(b)
    if root_a != root_b:
      if self.rank[root_a]>self.rank[root_b]:
        self.par[root_b] =root_a
      elif self.rank[root_a]<self.rank[root_b]:
        self.par[root_a] = root_b
      else:
        self.par[root_a] = root_b
        self.rank[root_b]+=1
      return True
    return False


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        nodes = {x for a,b in edges for x in (a,b)}
        n = max(nodes)
        myunion = unionfind(n+1)
        for a,b in edges:
          if not myunion.union(a,b):
            return [a,b]
        
                
                
            
              
        
        
        
          
        

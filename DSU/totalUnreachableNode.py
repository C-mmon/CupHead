from collections import Counter
class DSU:
    def __init__(self, n):
        self.parent=[i for i in range(n)]
        self.rank=[0]*n 
        #rank should be initialised with size zero
    def findRoot(self, root):
        if self.parent[root] != root:
            self.parent[root] = self.findRoot(self.parent[root])
        return self.parent[root]
    def Union(self,x, y):
        rootX = self.findRoot(x)
        rootY = self.findRoot(y)
        if rootX == rootY:
            return  
        if self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        elif self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1
#Thanks to path compression and union by rank, each findRoot() runs in nearly constant time, amortized O(α(n)), where α(n) is the inverse Ackermann function 
#analyzes the average time taken by a sequence of operations, not the worst-case complexity of individual operations
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        for u, v in edges:
            dsu.Union(u, v)
        
        #we need to check how many nodes belong to each group
        
        #subclass of dictionary , count occurence efficienly
        component_sizes = Counter()
        for i in range(n):
            root = dsu.findRoot(i)
            component_sizes[root] += 1
        total= n
        total
        total_nodes = n
        total_pairs = total_nodes * (total_nodes - 1) // 2
        reachable_pairs = 0
        for size in component_sizes.values():
            reachable_pairs += size * (size - 1) // 2
        return total_pairs - reachable_pairs
            
        

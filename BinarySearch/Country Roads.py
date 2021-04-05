class Solution:
    def dfs(self, node, include):
        ans = 0

        if include:
            ans = self.population[node]
        
        for i in self.adj_matrix[node]:
            ans += self.dfs(i, not include)

        return ans

    def solve(self, source, dest, population):
        self.population = population
        n = len(population)

        # Construct adjacent matrix (it is a tree)
        self.adj_matrix = [[] for i in range(n)]
        for src, des in zip(source, dest):
            self.adj_matrix[src].append(des)

        # Find the root (the node that does not appear in dest)
        root = int((n * (n - 1) / 2) - sum(dest))

        self.ans = 0
        # Compare total of nodes at even level vs odd level
        self.ans = self.dfs(root, True)
        self.ans = max(self.ans, self.dfs(root, False))
        
        return self.ans
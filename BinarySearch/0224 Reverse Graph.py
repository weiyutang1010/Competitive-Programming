class Solution:
    def solve(self, graph):
        reversed_graph = [[] for i in range(len(graph))]

        for i, node in enumerate(graph):
            for adj_node in node:
                reversed_graph[adj_node].append(i)

        return reversed_graph
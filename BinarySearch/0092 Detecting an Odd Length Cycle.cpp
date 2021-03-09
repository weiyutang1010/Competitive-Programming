bool is_bipartite(vector<vector<int>>& graph, int src) {
    int n = graph.size(); // number of vertices

    // color of each node
    // -1 is not colored, 0 is blue, 1 is red
    vector<int> color(n, -1); 
    color[src] = 0;

    // bfs
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        // Find all non-colored adjacent vertices
        for (int& v: graph[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                // If same color then return false
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<int>>& graph) {
    // A graph with odd length cycle is not bipartite
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        // Test from all src since graph might be disconnected
        if (!is_bipartite(graph, i)) {
            return true;
        }
    }
    return false;
}
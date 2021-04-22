int solve(int n, vector<vector<int>>& edges) {
    int m = edges.size();
    vector<vector<array<int, 2>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> dist(n + 1, INT_MAX);
    dist[0] = 0;

    // {distance, node}
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 0});

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();

        for (auto& [v, w]: adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return *max_element(dist.begin(), dist.end());
}
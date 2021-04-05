#define f first
#define s second

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int solve(vector<vector<int>>& edges) {
    // n is the number of vertices
    // m is the number of edges
    int n = 0;
    for (auto& x: edges) {
        n = max(n, max(x[0], x[1]));
    }
    n++;
    int m = edges.size();

    sort(edges.begin(), edges.end(), comp);

    vector<vector<int>> graph(n);
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        int w = edges[i][2];
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);

        // bfs to find shortest path
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v: graph[u]) {
                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // avoid int overflow
        if (dist[n - 1] < INT_MAX)
            ans = min(ans, dist[n-1] * w);
    }

    return ans;
}
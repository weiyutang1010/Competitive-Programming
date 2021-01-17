#define f first
#define s second
#define ii pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<ii>> graph(N + 1);
        for (auto& t: times) {
            graph[t[0]].push_back({t[1], t[2]});
        }
        
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, K});
        
        int u, v, w;
        while (!pq.empty()) {
            ii node = pq.top(); pq.pop();
            u = node.s;
            for (auto& to: graph[u]) {
                v = to.f, w = to.s;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int ans = *max_element(dist.begin() + 1, dist.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};
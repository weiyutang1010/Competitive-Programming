class Solution {
public:
    int find_set(vector<int>& dsu, int node) {
        if (dsu[node] == node) return node;
        return dsu[node] = find_set(dsu, dsu[node]);
    }
    
    void union_sets(vector<int>& dsu, vector<int>& rank, int a, int b) {
        a = find_set(dsu, a);
        b = find_set(dsu, b);
        
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            dsu[b] = a;
            rank[a] += rank[b];
        }
    }
    
    void init_dsu(vector<int>& dsu) {
        for (int i = 0; i < (int)dsu.size(); i++) {
            dsu[i] = i;
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> dsu(isConnected[0].size());
        vector<int> rank(isConnected[0].size(), 1);
        
        init_dsu(dsu);
        
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j]) union_sets(dsu, rank, i, j);
            }
        }
        
        unordered_set<int> s;
        for (int i = 0; i < isConnected[0].size(); i++) {
            dsu[i] = find_set(dsu, i);
            s.insert(dsu[i]);
        }
        
        return s.size();
    }
};
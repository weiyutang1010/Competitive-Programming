class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;
        for (vector<int>& v: edges) {
            mp[v[0]]++, mp[v[1]]++;
        }
        
        for (auto& x: mp) {
            if (x.second == edges.size()) return x.first;
        }
        
        return 0;
    }
};
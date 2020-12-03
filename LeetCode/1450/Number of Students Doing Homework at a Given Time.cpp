class Solution {
public:
    int busyStudent(vector<int>& start, vector<int>& end, int query) {
        int n = start.size();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (query >= start[i] && query <= end[i]) {
                ans++;
            }
        }
        
        return ans;
    }
};
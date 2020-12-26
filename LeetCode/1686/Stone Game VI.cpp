class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
        // The value Alice get from picking A[i] is A[i] + B[i]
        // Sort v by A[i] + B[i] 
        vector<vector<int>> v;
        for (int i = 0; i < (int)A.size(); i++) {
            v.push_back({A[i] + B[i], A[i], B[i]});
        }
        sort(v.rbegin(), v.rend());
        
        int res[2] {0, 0}; // score of Alice and Bob
        for (int i = 0; i < v.size(); i++) {
            res[i % 2] += v[i][i % 2 + 1];
        }
        
        if (res[0] == res[1]) {
            return 0;
        } else if (res[0] > res[1]) {
            return 1;
        } else {
            return -1;
        }
    }
};
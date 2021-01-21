class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;
        
        // view each row and its above as pillars 
            // calculate heights
            // sort pillars
            // iterate to get the maxium rectangle
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) height[j] = 0;
                else height[j]++;
            }
            
            vector<int> temp_height = height;
            sort(temp_height.begin(), temp_height.end());
            
            for (int j = 0; j < n; j++) {
                ans = max(ans, temp_height[j] * (n - j));
            }
        }
        
        return ans;
    }
};
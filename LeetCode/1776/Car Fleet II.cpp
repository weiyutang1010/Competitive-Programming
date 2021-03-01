class Solution {
public: 
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> st;
        vector<double> ans(n, -1);
        
        for (int i = n - 1; i >= 0; i--) {
            int pos = cars[i][0], speed = cars[i][1];
            
            while(!st.empty()) {
                int j = st.top(), pos2 = cars[j][0], speed2 = cars[j][1];
                if (speed <= speed2 || 1.0 * (pos2 - pos) / (speed - speed2) >= ans[j] && ans[j] > 0) {
                    st.pop();
                } else {
                    break;
                }
            }
            
            if (!st.empty()) {
                int j = st.top();
                ans[i] = 1.0 * (cars[j][0] - pos) / (speed - cars[j][1]);
            }
            
            st.push(i);
        }
        
        return ans;
    }
};
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int ans = 0;
        int curr_lane = 2;
        
        vector<vector<int>> least_obs(n, vector<int> (3));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) {
                    least_obs[i][j] = 0;
                } else {
                    least_obs[i][j] = least_obs[i + 1][j] + 1;
                }
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (obstacles[i + 1] != curr_lane) {
                continue;
            }
            ans++;
            
            // If only 1 lane to jump
            if (obstacles[i] != 0) {
                for (int j = 0; j < 3; j++) {
                    if (j + 1 != curr_lane && j + 1 != obstacles[i]) {
                        curr_lane = j + 1;
                        break;
                    }
                }
                continue;
            }
            
            // Choose lane that is furthest away from the next rock
            pair<int, int> new_lane = {0, 0};
            for (int j = 0; j < 3; j++) {
                if (j + 1 == curr_lane) continue;
                if (least_obs[i][j] > new_lane.second) {
                    new_lane = {j, least_obs[i][j]};
                }
            }
            curr_lane = new_lane.first + 1;
        }
        return ans;
    }
};
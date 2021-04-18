class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Keep track of original index (before sorting)
        for (int i = 0; i < (int)tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        
        // {processing time, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        
        int pt = 0;
        int t = tasks[0][0];
        vector<int> ans;
        
        // Get tasks that are available to process at time t
        while (pt < (int)tasks.size()) {
            // Process available task until more tasks is available
            while (!pq.empty() && t < tasks[pt][0]) {
                ans.push_back(pq.top().second);
                t += pq.top().first;
                pq.pop();
            }
            
            t = max(t, tasks[pt][0]);
            // Push available task to pq
            while (pt < (int)tasks.size() && tasks[pt][0] <= t) {
                pq.push({tasks[pt][1], tasks[pt][2]});
                pt++;
                continue;
            }
        }
        
        // Process the rest of the tasks
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
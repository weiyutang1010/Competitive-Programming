vector<vector<int>> solve(vector<vector<int>>& intervals, vector<int>& target) {
    int n = intervals.size();
    int min_n = target[0], max_n = target[1];
    vector<vector<int>> ans;

    // Don't include interval that intersect with target
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][1] >= target[0] && intervals[i][0] <= target[1]) {
            min_n = min(min_n, intervals[i][0]);
            max_n = max(max_n, intervals[i][1]);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    // Include final interval by combining everything that intersect with target
    ans.push_back({min_n, max_n});
    sort(ans.begin(), ans.end(), [&] (const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    return ans;
}
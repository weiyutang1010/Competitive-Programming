vector<int> solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<int> ans(2);
    
    int min_n = INT_MAX, max_n = 0;
    for (int i = 0; i < n; i++) {
        min_n = min(min_n, intervals[i][1]);
        max_n = max(max_n, intervals[i][0]);
    }

    return vector<int> {max_n, min_n};
}
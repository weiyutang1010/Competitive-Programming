int solve(vector<int>& deadlines, vector<int>& credits, vector<int>& durations) {
    const int MAX_T = 201;
    int n = deadlines.size();

    vector<vector<int>> course (n, vector<int> (3, 0)); // course[i] = {deadlines, credits, durations}
    for (int i = 0; i < n; i++) {
        course[i][0] = deadlines[i] + 1;
        course[i][1] = credits[i];
        course[i][2] = durations[i];
    }

    sort(course.begin(), course.end()); 
    // Row - Time
    // Col - ith Course
    // dp[i][j] = max credit when course[i] ends at time j
    int ans = 0;
    vector<int> dp (MAX_T, 0);

    for (int i = 0; i < n; i++) {
        int deadline = course[i][0];
        int credit = course[i][1];
        int duration = course[i][2];
        vector<int> new_dp = dp;

        for (int j = duration; j <= deadline; j++) {
            new_dp[j] = max(dp[j], dp[j - duration] + credit);
            ans = max(new_dp[j], ans);
        }
        dp = new_dp;
    }


    return ans;
}
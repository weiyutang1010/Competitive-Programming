int solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end()); // sort intervals by starting time

    // best profit keep tracks of max value we've seen before
    int best_profit = 0, ans = 0;
    // pq = {end time, best profit seen so far} sorted in ascending order
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

    for (vector<int>& interval: intervals) {
        int curr_start = interval[0];
        int curr_end = interval[1];
        int curr_profit = interval[2];

        // if the end time from previous interval is less than current start time
        while (!pq.empty() && pq.top()[0] <= curr_start) {
            best_profit = max(best_profit, pq.top()[1]);
            pq.pop();
        }

        // push current interval with best profit + current profit
        pq.push({curr_end, best_profit + curr_profit});
        ans = max(ans, best_profit + curr_profit);
    }

    return ans;
}
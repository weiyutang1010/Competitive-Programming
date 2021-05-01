// From editorial, need to revise
#define f first
#define s second
vector<pair<int, int>> memo;

int countIntervals(vector<vector<int>>& intervals, int i, int end) {
    if (i == (int)intervals.size()) return 0;
    if (memo[i].f < end) {
        return INT_MIN;
    }
    if (memo[i].f == end) {
        return memo[i].s;
    }

    if (end < intervals[i][0]){
        memo[i]= {min(end,memo[i].f), 1 + countIntervals(intervals, i + 1, intervals[i][1])};
        return memo[i].s;
    }

    memo[i] = {min(end, memo[i].f), countIntervals(intervals, i+1, max(intervals[i][1], end))};
    return memo[i].s;
}

int solve(vector<vector<int>>& intervals) {
    int n = intervals.size();
    memo.clear();
    memo.resize(n, {INT_MAX, -1});
    sort(intervals.begin(), intervals.end());

    int count = 0, result = 0, end = -1;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        result = max(result, count + countIntervals(intervals, i + 1, end));
        if (end < intervals[i][0]) {
            count++;
        }
        end = max(end, intervals[i][1]);
    }

    return result;
}
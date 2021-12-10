int solve(vector<string>& shows, vector<int>& durations, int k) {
    int n = shows.size();
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        mp[shows[i]] += durations[i];
    }

    priority_queue<int> pq;
    for (auto& [show, time]: mp) {
        pq.push(time);
    }

	// Find k longest time
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += pq.top();
        pq.pop();
    }

    return ans;
}

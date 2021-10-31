int solve(vector<string>& words) {
    int n = words.size();
    unordered_map<string, int> mp;

    int ans = 1;
    for (int i = 0; i < n; i++) {
        sort(words[i].begin(), words[i].end());
        mp[words[i]]++;
        ans = max(ans, mp[words[i]]);
    }

    return ans;
}

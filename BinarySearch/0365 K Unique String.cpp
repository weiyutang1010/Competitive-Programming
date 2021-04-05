int solve(string s, int k) {
    int n = s.size();
    vector<int> cnt(26, INT_MAX);
    int uniq = 0;
    for (char& c: s) {
        if (cnt[c - 'a'] == INT_MAX) {
            uniq++;
            cnt[c - 'a'] = 0;
        }
        cnt[c - 'a'] += 1;
    }

    int ans = 0;
    sort(cnt.begin(), cnt.end(), [&] (const int a, const int b) {
        return a < b;
    });

    int i = 0;
    while (uniq > k && i < 26) {
        ans += cnt[i];
        i++;
        uniq--;
    }

    return ans;
}
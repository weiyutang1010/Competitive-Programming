int solve(string a, string b) {
    unordered_map<char, int> mp;
    for (char& c: a) {
        mp[c]++;
    }

    int ans = 0;
    for (char& c: b) {
        if (mp[c]) {
            mp[c]--;
            ans++;
        }
    }
    return ans;
}

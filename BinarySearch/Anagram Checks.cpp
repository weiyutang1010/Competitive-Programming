bool solve(string s0, string s1) {
    unordered_map<char, int> mp;
    int total = 0;
    for (char& c: s0) {
        mp[c]++;
        total++;
    }
    for (char& c: s1) {
        if (mp[c] == 0) return false;
        mp[c]--;
        total--;
    }
    return total == 0;
}
bool solve(string s) {
    unordered_map<char, int> mp;
    for (char& c: s) {
        mp[c]++;
        if (mp[c] >= 2) return false;
    }
    return true;
}
bool solve(string s) {
    unordered_map<char, int> mp;
    for (char& c: s) {
        mp[c]++;
    }

    bool odd = 0;
    for (auto& x: mp) {
        if (x.second & 1) {
            if (odd) return false;
            odd = 1;
        }
    }
    return true;
}
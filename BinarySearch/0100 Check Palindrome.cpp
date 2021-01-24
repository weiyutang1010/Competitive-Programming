bool solve(string s) {
    if (s.size() < 2) {
        return true;
    }
    return (s[0] == s[s.size() - 1]) && solve(s.substr(1, s.size() - 2));
}
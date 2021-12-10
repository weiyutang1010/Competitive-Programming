bool solve(string s, string t) {
    int n = s.size();

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    bool greater = true;
    bool smaller = true;
    for (int i = 0; i < n; i++) {
        if (s[i] < t[i]) greater = false;
        if (s[i] > t[i]) smaller = false;
    }

    return greater || smaller;
}

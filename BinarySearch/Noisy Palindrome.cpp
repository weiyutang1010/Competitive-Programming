bool solve(string s) {
    int n = s.size();
    for (int l = 0, r= n - 1; l < r; l++, r--) {
        while(l < r && (s[l] < 'a' || s[l] > 'z')) {
            l++;
        }
        while(r > l && (s[r] < 'a' || s[r] > 'z')) {
            r--;
        }
        if (l >= r) return true;
        if (s[l] != s[r]) return false;
    }
    return true;
}
int solve(string s) {
    int open = 0;
    int ans = 0;
    for (char& c: s) {
        if (c == '(') open++;
        else if (c == ')') {
            if (open > 0) {
                open--;
                ans++;
            }
        }
    }
    return ans * 2;
}
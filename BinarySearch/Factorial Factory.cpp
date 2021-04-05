int solve(int n) {
    if (n == 0) return 1;
    int ans = n;
    for (int i = n - 1; i >= 2; i--) {
        ans *= i;
    }
    return ans;
}
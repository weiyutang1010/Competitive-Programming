int solve(int n) {
    const int MOD = 1e9 + 7;
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<int> ans(n);
    ans[0] = 1, ans[1] = 2;

    for (int i = 2; i < n; i++) {
        ans[i] = (ans[i - 1] % MOD) + (ans[i - 2] % MOD);
    } 

    return (ans[n - 1] % MOD);
}
int solve(int r, int c) {
    if (r <= 1 || c <= 1) return 0;

    int MOD = 1e9 + 7;
    int max_sz = min(r, c);
    int64_t ans = 0;

    for (int i = 1;  i < max_sz; i++) {
        int64_t val = ((r - i) % MOD) * ((c - i) % MOD);
        if (val <= 0) continue;
        if (i > 1) val = (val * i) % MOD;
        ans += val % MOD;
    }

    return ans % MOD;
}
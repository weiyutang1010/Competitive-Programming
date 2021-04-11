int solve(int num) {
    int64_t ans = 0;
    while (num > 0) {
        // Add and remove last digit from num
        ans += num % 10;
        num /= 10;
    }

    return ans;
}
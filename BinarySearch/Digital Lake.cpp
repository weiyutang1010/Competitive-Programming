int64_t count_in_range(int n, int d, int i) {
    int64_t pow_of_10 = pow(10, i);
    int64_t next_pow_of_10 = pow_of_10 * 10;
    int64_t right = n % pow_of_10;

    // get digit at index i
    int digit = (n / pow_of_10) % 10;

    int64_t round_down = n - (n % next_pow_of_10);
    int64_t round_up = round_down + next_pow_of_10;

    if (digit < d) {
        return round_down / 10;
    } else if (digit == d) {
        return round_down / 10 + right + 1;
    } else {
        return round_up / 10;
    }
}

int solve(int n, int d) {
    string st = to_string(n);
    int len = st.size();

    int64_t count = 0;
    for (int i = 0; i < len; i++) {
        count += count_in_range(n, d, i);
    }

    if (d == 0) {
        for (int i = 0; i < len; i++) {
            count -= pow(10, i);
        }
    }

    return count;
}
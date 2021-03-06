bool solve(int n) {
    string st = to_string(n);
    int sz = st.size();

    int64_t sum = 0;
    for (int i = 0; i < sz; i++) {
        sum += pow((st[i] - '0'), sz);
    }

    return sum == n;
}
int solve(int n) {
    int count = 0;
    while (n != 1) {
        count++;
        if (n & 1) n = 3 * n + 1;
        else n = n / 2;
    }
    return count + 1;
}
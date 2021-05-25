int solve(int n) {
    // We will place 1 rook in each row
    // Everytime we place 1 rook, we have n - 1 column left to choose to place next rook
    // So we get n * n - 1 * n - 2 * ... * 1 as total number of options (n!)
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
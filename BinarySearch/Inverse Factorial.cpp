int solve(int a) {
    int fact = 1;
    // Find n * (n - 1) * (n - 2)... from 1 to a and see if there's any matching answer
    for (int i = 1; i <= a; i++) {
        fact *= i;
        if (fact == a) {
            return i;
        }
    }
    return -1;
}
int solve(int n) {
    int temp = 0;
    vector<int> bin;
    while (n > 0) {
        if (n%2 == 1) temp = 1;
        bin.push_back(n % 2);
        n /= 2;
    }

    int consec = 0, curr = 0;
    for (int i = 1; i < (int)bin.size(); i++) {
        if (bin[i] == 1 && bin[i] == bin[i - 1]) {
            curr++;
        } else {
            consec = max(consec, curr);
            curr = 0;
        }
    }
    return max(consec, curr) + temp;
}
string solve(int n) {
    string s = "1";
    for (int i = 1; i < n; i++) {
        string new_s = "";
        int sz = s.size();

        char val = s[0];
        int count = 1;
        for (int j = 1; j < sz; j++) {
            if (s[j] != val) {
                new_s += to_string(count);
                new_s += val;
                count = 0;
            }
            val = s[j];
            count++;
        }
        new_s += to_string(count);
        new_s += val;
        s = new_s;
    }
    return s;
}
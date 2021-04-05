bool comp(const int& a, const int& b) {
    string str1 = to_string(a);
    string str2 = to_string(b);

    int n = str1.size(), m = str2.size();
    for (int i = 0; i < max(n, m); i++) {
        if (str1[i] != str2[i]) {
            return str1[i] < str2[i];
        }
    }
    return false;
}

vector<int> solve(int n) {
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        ans[i - 1] = i;
    }

    sort(ans.begin(), ans.end(), comp);
    return ans;
}
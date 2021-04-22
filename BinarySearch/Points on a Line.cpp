int solve(vector<vector<int>>& C) {
    // y = mx + c
    // If two points are on the same line, they have the same gradient(m) and y-intercept(c)
    int n = C.size();
    if (n == 1) return 1;

    int ans = 0;
    // {m, c} = count of pair of points with same m and c
    map<pair<double, double>, int> cnt; 
    double m = 0.0, c = 0.0;

    for (int i = 1; i < n; i++) {
        // Use a set to prevent double counting
        set<pair<double, double>> st;

        for (int j = 0; j < i; j++) {
            if (C[i][0] - C[j][0] != 0) {
                // Calculate m and c where m = (y1 - y0) / (x1 - x0) and c = y - mx
                m = (C[i][1] - C[j][1]) / (double)(C[i][0] - C[j][0]);
                c = C[i][1] - m * C[i][0];
            } else {
                // case where the points are on a vertical line
                // set m = infinity and c = x-intercept
                m = DBL_MAX;
                c = C[i][0];
            }
            st.insert(make_pair(m, c));
        }

        for (const auto& x: st) {
            if (cnt[x] == 0) {
                // initially we add 2 points
                cnt[x] = 2;
            } else {
                // add only 1 since
                // one of the points would already be counted
                cnt[x]++;
            }
        }
    }

    for (auto& [x, y] : cnt) {
        ans = max(ans, y);
    }

    return ans;
}
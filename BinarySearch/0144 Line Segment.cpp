bool solve(vector<vector<int>>& C) {
    if (C.size() <= 1) return true;
    
    if (C[1][0] == C[0][0]) {
        for (int i = 2; i < (int) C.size(); i++) {
            if (C[i][0] != C[0][0]) {
                return false;
            }
        }
        return true;
    }

    double slope = (C[1][1] - C[0][1]) / (C[1][0] - C[0][0]);
    int intercept = C[0][1] - slope * C[0][0];

    for (int i = 2; i < (int)C.size(); i++) {
        if (C[i][1] != (slope * C[i][0] + intercept)) {
            return false;
        }
    }
    return true;
}
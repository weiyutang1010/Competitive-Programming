#define f first
#define s second

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    pair<int,int> min_value = {INT_MAX, 0}, second_min = {INT_MAX, 0}; // {value, index}
    
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] < min_value.f) {
            second_min = min_value;
            min_value = {matrix[0][j], j};
        } else if (matrix[0][j] < second_min.f) {
            second_min = {matrix[0][j], j};
        }
    }

    for (int i = 1; i < n; i++) {
        pair<int,int> min_value2 = {INT_MAX, 0}, second_min2 = {INT_MAX, 0};
        for (int j = 0; j < m; j++) {
            if (j == min_value.s) {
                matrix[i][j] += second_min.f;
            } else {
                matrix[i][j] += min_value.f;
            }

            if (matrix[i][j] < min_value2.f) {
                second_min2 = min_value2;
                min_value2 = {matrix[i][j], j};
            } else if (matrix[i][j] < second_min2.f) {
                second_min2 = {matrix[i][j], j};
            }
        }
        min_value = min_value2;
        second_min = second_min2;
    }

    return *min_element(matrix[n-1].begin(), matrix[n-1].end());
}
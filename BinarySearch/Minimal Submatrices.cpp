// Min queue method can be found from here:
// https://cp-algorithms.com/data_structures/stack_queue_modification.html
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// The idea is to use min_queue to keep track of min element in each subarray of length k
// We first use min_queue across each row then each column and reduce matrix to (n - k + 1, m - k + 1) size

void min_slide_row(vector<vector<int>>& matrix, vector<vector<int>>& v, int i, int k, int n, int m) {
    deque<int> dq;
    for (int j = 0; j < k; j++) {
        while (!dq.empty() && matrix[i][j] < dq.back())
            dq.pop_back();
        dq.push_back(matrix[i][j]);
    }

    for (int j = k; j < m; j++) {
        v[i][j-k] = dq.front();
        
        if (!dq.empty() && dq.front() == matrix[i][j-k]) {
            dq.pop_front();
        }

        while (!dq.empty() && matrix[i][j] < dq.back())
            dq.pop_back();
        dq.push_back(matrix[i][j]);
    }
    v[i][m-k] = dq.front();
}

void min_slide_col(vector<vector<int>>& matrix, vector<vector<int>>& v, int j, int k, int n, int m) {
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && matrix[i][j] < dq.back())
            dq.pop_back();
        dq.push_back(matrix[i][j]);
    }

    for (int i = k; i < n; i++) {
        v[i-k][j] = dq.front();
        
        if (!dq.empty() && dq.front() == matrix[i-k][j]) {
            dq.pop_front();
        }

        while (!dq.empty() && matrix[i][j] < dq.back())
            dq.pop_back();
        dq.push_back(matrix[i][j]);
    }
    v[n-k][j] = dq.front();
}

vector<vector<int>> solve(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> v1(n, vector<int> (m - k + 1));
    for (int i = 0; i < n; i++) {
        // min sliding window for each row
        min_slide_row(matrix, v1, i, k, n, m);
    }

    vector<vector<int>> v2(n - k + 1, vector<int> (m - k + 1));
    for (int j = 0; j < m - k + 1; j++) {
        // min sliding window for each column
        min_slide_col(v1, v2, j, k, n, m - k + 1);
    }

    return v2;
}
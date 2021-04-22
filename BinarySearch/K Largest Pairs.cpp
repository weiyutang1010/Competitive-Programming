int solve(vector<int>& a, vector<int>& b, int k) {
    if (k == 0) return 0;
    int n = a.size(), m = b.size(), sum = 0;
    sort(a.begin(), a.end());
    // pq = {sum, index of a[i], value of b[i]}
    priority_queue<vector<int>> pq;
    // Pair the largest element of a with b
    for (int i = 0; i < m; i++) {
        pq.push({a[n-1] + b[i], n - 1, b[i]});
    }
    while (k--) {
        // Get the pair with largest sum
        vector<int> v = pq.top();
        pq.pop();
        sum += v[0];
        // Pair the next smaller a[i] with b[i]
        if (v[1] > 0) pq.push({a[v[1] - 1] + v[2], v[1] - 1, v[2]});
    }
    return sum;
}
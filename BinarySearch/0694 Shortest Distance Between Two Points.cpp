int dist(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
}

int find_smallest_dist(vector<vector<int>>& C, int l, int r) {
    // If less than 2 then calculate distance
    if (l >= r) return INT_MAX;
    if (r - l == 1) {
        return dist(C[l], C[r]);
    }

    int mid = (l + r) / 2;
    // Find smallest distance in left and right halves
    int dl = find_smallest_dist(C, l, mid);
    int dr = find_smallest_dist(C, mid, r);

    int d = min(dl, dr);

    // Find points that are less than distance d away from midline
    for (int i = l; i <= r; i++) {
        if (C[i][0] >= mid - d && C[i][0] <= mid + d) {
            for (int j = i + 1; j <= r; j++) {
                d = min(d, dist(C[i], C[j]));
            }
        }
    }

    return d;
}

int solve(vector<vector<int>>& C) {
    // Sort array based on x coordinates
    sort (C.begin(), C.end());

    return find_smallest_dist(C, 0, C.size()-1);
}
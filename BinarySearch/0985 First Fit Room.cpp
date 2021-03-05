int solve(vector<int>& rooms, int target) {
    int n = rooms.size();
    for (int i = 0; i < n; i++) {
        if (rooms[i] >= target) return rooms[i];
    }
    return -1;
}